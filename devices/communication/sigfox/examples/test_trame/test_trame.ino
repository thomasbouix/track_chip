#include "Wisol.h"
void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char lat_c,lng_c;
  int lat_minute, lat_angle;
  double lat_seconde;
  int lng_minute, lng_angle;
  double lng_seconde;
  
 Wisol w;
 String trame = "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";
 w.trame_GPGGA_to_DMS(trame, &lat_angle, &lat_minute, &lat_seconde, &lat_c, &lng_angle, &lng_minute, &lng_seconde, &lng_c);
  Serial.println("lat : ");
  Serial.println(lat_angle);
  Serial.println(lat_minute);
  Serial.println(lat_seconde);
  Serial.println(lat_c);
  Serial.println("lng : ");
  Serial.println(lng_angle);
  Serial.println(lng_minute);
  Serial.println(lng_seconde);
  Serial.println(lng_c);
  int altitude = 14;
  w.send_trame(lat_angle, lat_minute, lat_seconde, lat_c, lng_angle, lng_minute, lng_seconde, lng_c, altitude);
  while(1);
}
