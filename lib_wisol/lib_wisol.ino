#include <HardwareSerial.h>
#include <string>

#define RXD2 16
#define TXD2 17

String retour;

bool IsHexCharOrNewLine(char c)
{
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'F') ||
           (c >= 'a' && c <= 'f') ||
           c == '\n'; // You may want to test for \r as well
}

bool IsHex(char* text)
{
    bool temp = true;
    for (int i = 0; i < strlen(text); i++){ 
      temp = temp && IsHexCharOrNewLine(text[i]);
    }
    return temp;
}


bool string_ok(String verif){
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

void send_string_data(HardwareSerial wisol, String envoie) {
  if( string_ok(envoie)) { 
    String command = "AT$SF=";
    command = command + envoie;
    Serial.println(command);
    wisol.println(command);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  String envoie = "0012FF3145";
  send_string_data(Serial2, envoie); 
  send_string_data(Serial2, "0012FF3145123");
  send_string_data(Serial2, "0012FF314512");
  send_string_data(Serial2, "0012GG");
}

void loop() {
  // put your main code here, to run repeatedly:
    while (Serial2.available()>0) {
    retour = Serial2.readStringUntil('\n');
    Serial.println(retour);
  }

}
