#include "wisol.h"

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
    if (n > 12){
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
