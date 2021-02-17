#include "TrackChip.h"

TrackChip trackChip = TrackChip();

String position, message;
float altitude;
  
void setup() {

  Serial.begin(115200); 
  while (!Serial); 

  trackChip.connect_to_wifi();
  trackChip.wifi_scan();
  if (trackChip.send_mac_and_get_pos() < 0 ) {
    Serial.println("Error in send_mac_and_get_pos()");
  }

  int prc;
  float lat, lng;

  prc = trackChip.get_wifi_accuracy();
  lat = trackChip.get_wifi_lat();
  lng = trackChip.get_wifi_lng();

  Serial.print("prc = "); Serial.println(prc);
  Serial.print("lat = "); Serial.println(lat);
  Serial.print("lng = "); Serial.println(lng);
  //Serial.println(trackChip.get_bssid());
  // trackChip.send_data("004A882F000398DC2F");

}

void loop() {
  
  //altitude = trackChip.get_altitude();
  //position = trackChip.get_position();
   
  Serial.println("========");
  Serial.print("altitude : "); Serial.print(altitude); Serial.println("m");
  Serial.print("position : "); Serial.println(position);
  /*Serial.print("res : ");
  String res = trackChip.create_message1();
  Serial.println(res);
  Serial.print("Taille message 1 : ");
  Serial.println(res.length());
  res = trackChip.create_message2();
  Serial.println(res);
  Serial.print("Taille message 2 : ");
  Serial.println(res.length());
  res = trackChip.create_message3();
  Serial.println(res);
  Serial.print("Taille message 3 : ");
  Serial.println(res.length());*/
  trackChip.chose_message_to_send();

  while(1);

}
