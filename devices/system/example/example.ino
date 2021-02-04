#include <TrackChip.h>

TrackChip trackChip = TrackChip();
	
void setup() {

	Serial.begin(115200); 
	while (!Serial);

  String message = "004A882F000398DC2F";
  Serial.println("====SENDING MESSAGE===");
  // trackChip.send_data(message);
  Serial.println("=====MESSAGE SENT===");
}

void loop() {
  
  float altitude = trackChip.get_altitude();
  String position = trackChip.get_position();
  Serial.println("========");
  Serial.print("altitude : "); Serial.print(altitude); Serial.println("m");
  Serial.print("position : "); Serial.println(position);

  delay(1000);

}
