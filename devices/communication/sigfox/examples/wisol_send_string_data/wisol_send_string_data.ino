#include "Wisol.h"

String retour;

void setup() {
	Serial.begin(115200);
	Wisol w;
	w.send_string_data("004A882F000398DC2C");
}

void loop() {    

	Serial.println("Entering loop");

	while (Serial2.available() > 0) {
		retour = Serial2.readStringUntil('\n');
		Serial.println(retour);
	}

	for(;;) {}
}
