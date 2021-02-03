#include <TrackChip.h>

TrackChip trackChip = TrackChip();
	
void setup() {

	Serial.begin(115200); 
	while (!Serial);

  String res;

  Serial.println("sending message");
  trackChip.send_data("004A882Fa000398DC2E");
  Serial.println("message sent");

  Serial.println("getting altitude");
  trackChip.get_altitude();
  // Serial.print("altitude : "); Serial.print(altitude); Serial.println("m");

}

void loop() {

}
