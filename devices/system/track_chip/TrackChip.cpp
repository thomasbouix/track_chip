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

void TrackChip::test_pointeur_bmp() {

	Serial.println("=========\n");
	Serial.println("test_pointeur_bmp");
	static int cpt = 0;

	if (cpt == 0) {
		BMP180I2C * bmp180 = new BMP180I2C(BMP_I2C_ADDRESS);  
		bmp180->init();
		cpt++;
		Serial.println("initing device");
	}
	
	BMP180I2C * bmp180 = new BMP180I2C(BMP_I2C_ADDRESS);  
	float altitude = bmp180->computeAltitude();

	Serial.print("altitude : ");
	Serial.print(altitude);
	Serial.println("m");  

	delete bmp180;
}


void TrackChip::test_objet_bmp() {
	
	Serial.println("=========\n");
	Serial.println("test_objet_bmp");
	BMP180I2C bmp180(BMP_I2C_ADDRESS);  
  	bmp180.init();

	float altitude = bmp180.computeAltitude();

	Serial.print("altitude : ");
	Serial.print(altitude);
	Serial.println("m");  

}

void TrackChip::test_objet_wisol() {
	
	Serial.println("=========\n");
	Serial.println("test_objet");

	Wisol wisol = Wisol();
	wisol.send_string_data("000000");
}

void TrackChip::test_pointeur_wisol() {
	
	Serial.println("=========\n");
	Serial.println("test_objet");

	Wisol * wisol = new Wisol();
	wisol->send_string_data("000001");

	delete wisol;
}


