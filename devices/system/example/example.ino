#include <TrackChip.h>

TrackChip trackChip = TrackChip();

String position, message;
float altitude;
  
void setup() {

  Serial.begin(115200); 
  while (!Serial);

  message = "004A882F000398DC2F";
  // trackChip.send_data(message);

}

void loop() {
  
  altitude = trackChip.get_altitude();
  position = trackChip.get_position();

  Serial.println("========");
  Serial.print("altitude : "); Serial.print(altitude); Serial.println("m");
  Serial.print("position : "); Serial.println(position);

  delay(1000);

}
