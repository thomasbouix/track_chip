// Programme de test

#include <iostream>
#include "Structure_Sigfox.h"

// convertis aussi bien la latitude que la longitude. Cette fonction suppose que le paramètre cardinal est N, S, E ou O.
double Dms_to_dd(char cardinal, int angle, int minute, double seconde){
	double res = angle;
	double temp = seconde/60;
	res += (minute+temp)/60;
	if( cardinal == 'S' || cardinal == 'O') { res = -res;}
	return res;
	}
double shift_latitude(double lat){
	return lat+180;
}

double shift_longitude(double lng){
	return lng+90;
}

string complete_hexa_bytes(string hexa, int nb_bytes){ // prend en argument une chaine hexa et le nombre d'octets voulu pour le callback et complete avec des 0 big edians
	int add = 2*nb_bytes - hexa.length();
	string complete = "";
	for(int i = 0; i<add;i++){
	complete = complete+"0";
	}
	return complete +hexa;
}

string dms_lat_to_trame_hexa(char cardinal, int angle, int minute, double seconde,int prec){
	double dd = shift_latitude(Dms_to_dd(cardinal,angle,minute, seconde));
    string res_lat = Message::double_to_hexa(dd,prec);
	res_lat = complete_hexa_bytes(res_lat,4);
	return res_lat;
}

string dms_lng_to_trame_hexa(char cardinal, int angle, int minute, double seconde,int prec){
	double dd = shift_longitude(Dms_to_dd(cardinal,angle,minute, seconde));
    string res_lat = Message::double_to_hexa(dd,prec);
	res_lat = complete_hexa_bytes(res_lat,4);
	return res_lat;
}

string altitude_to_trame_hexa(int altitude){
	string res_alt = Message::int_to_hexa(altitude);
	return complete_hexa_bytes(res_alt,2);
}

int main() {
    Message m = Message();
    
    string res;
    //res = m.int_to_hexa(314);
    //std::cout << res;
    double lat =  48.84527;
    int prec = 5;
    int res_int;
    res_int= m.double_to_int(lat, prec);
    //std::cout << res_int<<endl;
    
    res = m.double_to_hexa(lat,prec);//tester sur un plage de valeur d'etrée de 0 à 270;
    //std::cout << res<<endl;
    //std::cout<<Dms_to_dd('N',48, 51, 17.005)<<endl;
    //std::cout<<Dms_to_dd('E',2, 21, 0.749)<<endl; // !!!Attention!!! Ne tient pas compte du signe ==> int_to_hexa
    /*std::cout<<"Test Général"<<endl;
    lat = shift_latitude(Dms_to_dd('N',48, 51, 17.005));
    double lng = shift_longitude(Dms_to_dd('E',2, 21, 0.749));
    std::cout << lat<<endl;
    std::cout << lng<<endl;
    
    int altitude = 55;
    
    string res_lat = m.double_to_hexa(lat,prec);
    std::cout << res_lat<<endl;
    std::cout <<complete_hexa_bytes(res_lat,4)<<endl;
    string res_lng = m.double_to_hexa(lng,prec);
    std::cout << res_lng<<endl;
    std::cout <<complete_hexa_bytes(res_lng,4)<<endl;
    string res_alt = m.int_to_hexa(altitude);
    std::cout << res_alt<<endl;
    std::cout <<complete_hexa_bytes(res_alt,2)<<endl;
    res = res_lat+res_lng+ res_alt;
    std::cout << res<<endl;*/
    std::cout<<"Test Latitude"<<endl;
    string res_lat = dms_lat_to_trame_hexa('N',48, 51, 17.005,5);
    std::cout << res_lat<<endl;
    
    std::cout<<"Test Longitude"<<endl;
    string res_lng = dms_lng_to_trame_hexa('E',2, 21, 0.749,5);
    std::cout << res_lng<<endl;
    
   std::cout<<"Test altitude"<<endl;
   string res_alt = altitude_to_trame_hexa(55);
   std::cout << res_alt<<endl;
}
