#include "TrackChip.h"

String position, message;
float lat, lng, altitude;
int prc;

TrackChip trackChip = TrackChip();

void setup() {

	Serial.begin(115200); 
	while (!Serial); 
}

void loop() {
  
	trackChip.wifi_scan();
	trackChip.chose_message_to_send();

  Serial.println("============");
  Serial.println(millis());
  Serial.println("============"); 

	delay(1000*60*1);
}
