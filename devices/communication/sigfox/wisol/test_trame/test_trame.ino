#include "Wisol.h"
void setup() {
  // put your setup code here, to run once:
  //Wisol w;
  Serial.begin(115200);
  //Serial.println(w.verif_type("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E"));
  
}

void loop() {
  // put your main code here, to run repeatedly:
 Wisol w;
String trame = "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";
 if( w.verif_type(trame)) {
  Serial.println("GPGGA");
  }
  char delimiter = ',';
  /*String token = trame.substring(0, trame.indexOf(delimiter));
  Serial.println(token);
  trame.remove(0, trame.indexOf(delimiter)+1);
  Serial.println(trame);
  token = trame.substring(0, trame.indexOf(delimiter));
  Serial.println(token);*/
  //int param_arecup[3,4,5,6];
  float lat_dms,lng_dms;
  char lat_c,lng_c;
  int param_suppr = 0;
  String token; 
  char* buf;
  /*while(param_suppr <=6){
    token = trame.substring(0, trame.indexOf(delimiter));
    Serial.println(token);
    if(param_suppr == 3){
      Serial.println("here ");
      lat_dms = token.toInt();
      }
    else if( param_suppr == 4){lng_dms = token.toInt();}
    else if(param_suppr == 5){
      token.toCharArray(buf,1);
      lat_c = buf[0];
      }
    else if (param_suppr == 6){
      token.toCharArray(buf,1);
      lng_c = buf[0];
      }
    trame.remove(0, trame.indexOf(delimiter)+1);
    param_suppr+=1;
    Serial.println(param_suppr);
  }*/
  //String res = "lat : "+lat_dms;//" "+lat_c+", lng : "+lng_dms+" "+lng_c;
  String test = "00740.9373";
  float test_float = test.toFloat();
  Serial.println(test_float);
  String cardinal = "E";
  cardinal.toCharArray(buf,1);
  lat_c = buf[0];
  //Serial.println(lat_c,DEC); //cette ligne fait buggé
  //Serial.println("lat :");
  //Serial.println(lat_dms);
  //Serial.println(lat_c);
  delay(5000);
}
