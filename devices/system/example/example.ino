#include <TrackChip.h>

TrackChip trackChip = TrackChip();
	
void setup() {

	Serial.begin(115200); 
	while (!Serial);

  String message = "004A882F000398DC2F";
  Serial.println("========");
  Serial.println("sending message");
  trackChip.send_data(message);
  Serial.println("message sent");
  Serial.println("========");
}

void loop() {
  
  float altitude = trackChip.get_altitude();
  Serial.print("altitude : "); Serial.print(altitude); Serial.println("m");

  // Serial.println("========");
  // Serial.println(trackChip.get_position());

  delay(1000);

}
