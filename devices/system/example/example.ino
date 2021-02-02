#include <TrackChip.h>

TrackChip trackChip = TrackChip();
	
void setup() {

	Serial.begin(115200); 
	while (!Serial);
}

void loop() {

	String res;

	res = trackChip.get_all_data();
	Serial.print(res);

	trackChip.send_data("hello");

	while(1);

}
