#include "TrackChip.h"

TrackChip::TrackChip() {
	this->gps = new GROVE11302();
	Wire.begin();
}

TrackChip::~TrackChip() {

}

void TrackChip::send_data(String s) {

	// Envoyer uniquement des chaines de la forme :
	// 004A882F000398DC2F 

	// insérer vérification

	Wisol wisol = Wisol();
	wisol.send_string_data(s);
}

float TrackChip::get_altitude() {

	static bool init = true; 
	static BMP180I2C bmp = BMP180I2C(BMP_I2C_ADDRESS);

	if (init) {
		Serial.println("TrackChip::get_altitude() => bmp init");
		bmp.init();
		init = false;
	}

	return bmp.computeAltitude();
}

String TrackChip::get_position() {
	
	gps->get_data_line();
	String res = (char*) (gps->buffer);

	return res;
}
