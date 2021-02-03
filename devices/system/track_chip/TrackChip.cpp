#include "TrackChip.h"

TrackChip::TrackChip() {

	this->bmp180	= new BMP180I2C(BMP_I2C_ADDRESS);
	this->gps	= new GROVE11302();			// RX0, TX0
	this->wisol	= new Wisol();				// RX2, TX2

	Wire.begin();

	if ( bmp180->init() < 0 ) goto error;	

	return;
	
	error : Serial.println("Error in TrackChip Constructor"); 
}

void TrackChip::send_data(String s) {

	wisol->send_string_data(s);
}

String TrackChip::get_all_data() {

	String res;

	float altitude;
	altitude = get_altitude();

	gps->get_data_line();
	String buffer((char*) gps->buffer);

	res += "\n=============\n";
	res += "buffer : "; 
	res += buffer; 
	res += "altitude : ";
	res += altitude;
	res += " m";	
	res += "\n=============\n";

	return res;
}  

float TrackChip::get_altitude() {

	return bmp180->computeAltitude();
}


