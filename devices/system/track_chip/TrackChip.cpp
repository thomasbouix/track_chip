#include "TrackChip.h"

TrackChip::TrackChip() {

	*bmp180		= BMP180I2C(BMP_I2C_ADDRESS);   
	*gps_grove	= GROVE11302();
	*w		= Wisol();

	Wire.begin();
	bmp180->init();
}

void TrackChip::send_data(String s) {
	w->send_string_data(s);
}  

String TrackChip::get_all_data() {

	String res;
	float altitude;

	altitude = bmp180->computeAltitude();
	gps_grove->get_data_line();
	String buffer((char*) gps_grove->buffer);

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


