#include <TrackChip.h>

TrackChip track_chip = TrackChip();
  
void setup() {

	Serial.begin(115200); 
	while (!Serial);
}

void loop() {

	String res;

	res = track_chip.get_all_data();
	Serial.print(res);

	Serial.print("altitude : ");
	Serial.print(track_chip.get_altitude());

	delay(1000);
}
