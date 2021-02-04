/*
Librairie permettant d'envoyer une chaine de caractère de 12 octets d'un ESP32 vers un module Sigfox Wisol
*/
#include "Wisol.h"

//Constructor
Wisol::Wisol(int baudrate, int RX, int TX){
	Serial2.begin(baudrate, SERIAL_8N1, RX, TX);
}

Wisol::Wisol(){
	Wisol(9600, RXD2, TXD2);
}

//private function
 bool Wisol::IsHexCharOrNewLine(char c){
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'F') ||
           (c >= 'a' && c <= 'f') ||
           c == '\n'; // You may want to test for \r as well
}

bool Wisol::IsHex(char* text){
{
    bool temp = true;
    for (int i = 0; i < strlen(text); i++){ 
      temp = temp && IsHexCharOrNewLine(text[i]);
    }
    return temp;
}
}

bool Wisol::string_ok(String verif){
    //verifier que la string fait moins de 12 octets
    int n = verif.length() ;
    if (n > 24){
      Serial.println("string too long");
      return false;
    }
    char char_array[n + 1];
    strcpy(char_array, verif.c_str());
    //qu'elle ne contient que des caractères Hexa
    return IsHex(char_array);
}

//public function

void Wisol::send_string_data(String envoie) {
  if( string_ok(envoie)) { 
    String command = "AT$SF=";
    command = command + envoie;
    Serial2.println(command);
  }
}

String Wisol::double_to_hexa(double a, int prec){
		String message = "";
		int temp;
		temp = double_to_int(a, prec);
		//std::cout << temp<<endl;
		message = int_to_hexa(temp);
		return message;
	}
	
String Wisol::int_to_hexa(int a){
 		char hex_string[20];
   		sprintf(hex_string, "%X", a); //convert number to hex
   		return hex_string;
 	}


int Wisol::double_to_int(double a, int prec){
	int res = round(a*pow (10, prec));
	//std::cout << res<<std::endl;
	return res;
}


// convertis aussi bien la latitude que la longitude. Cette fonction suppose que le paramètre cardinal est N, S, E ou O.
double Wisol::Dms_to_dd(char cardinal, int angle, int minute, double seconde){
	double res = angle;
	double temp = seconde/60;
	res += (minute+temp)/60;
	if( cardinal == 'S' || cardinal == 'O') { res = -res;}
	return res;
	}
	
double Wisol::shift_latitude(double lat){
	return lat+180;
}

double Wisol::shift_longitude(double lng){
	return lng+90;
}

String Wisol::complete_hexa_bytes(String hexa, int nb_bytes){ // prend en argument une chaine hexa et le nombre d'octets voulu pour le callback et complete avec des 0 big edians
	int add = 2*nb_bytes - hexa.length();
	String complete = "";
	for(int i = 0; i<add;i++){
	complete = complete+"0";
	}
	return complete +hexa;
}

String Wisol::dms_lat_to_trame_hexa(char cardinal, int angle, int minute, double seconde,int prec){
	double dd = shift_latitude(Dms_to_dd(cardinal,angle,minute, seconde));
  String res_lat = Wisol::double_to_hexa(dd,prec);
	res_lat = complete_hexa_bytes(res_lat,4);
	return res_lat;
}

String Wisol::dms_lng_to_trame_hexa(char cardinal, int angle, int minute, double seconde,int prec){
	double dd = shift_longitude(Dms_to_dd(cardinal,angle,minute, seconde));
  String res_lat = Wisol::double_to_hexa(dd,prec);
	res_lat = complete_hexa_bytes(res_lat,4);
	return res_lat;
}

String Wisol::altitude_to_trame_hexa(int altitude){
	String res_alt = Wisol::int_to_hexa(altitude);
	return complete_hexa_bytes(res_alt,2);
}
