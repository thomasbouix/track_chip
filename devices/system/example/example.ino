#include <TrackChip.h>

TrackChip trackChip = TrackChip();
	
void setup() {

	Serial.begin(115200); 
	while (!Serial);

  String res;

  Serial.println("sending message");
  trackChip.send_data("00005");
  trackChip.wisol->send_string_data("00000"); 
  Serial.println("message sent");

  /*
  Serial.println("getting altitude");
  float altitude = trackChip.get_altitude();
  Serial.print("altitude : "); Serial.print(altitude); Serial.println("m");
  */

}

void loop() {

      // trackChip.test_objet_bmp();
      // trackChip.test_pointeur_bmp();

      delay(1000);

}
