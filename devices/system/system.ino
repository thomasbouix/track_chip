#include <Arduino.h>
#include <BMP180I2C.h>
#include <GROVE11302.h>
#include <Wisol.h>

#define BMP_I2C_ADDRESS 0x77 

BMP180I2C bmp180 = BMP180I2C(BMP_I2C_ADDRESS);
GROVE11302 gps_grove = GROVE11302();
Wisol w;

float altitude;
String retour;

void print_data() {

	altitude = bmp180.computeAltitude();
	gps_grove.get_data_line();

	Serial.print("\n=============\n");
	Serial.print("buffer : "); 
	Serial.write(gps_grove.buffer, 70);
	Serial.print("altitude : ");
	Serial.print(altitude);
	Serial.println("m");	
	Serial.print("\n=============\n");
}

void send_data() {
	w.send_string_data("004A882F000398DC2E");
}

void setup() {

	Serial.begin(115200); 
	while (!Serial);
	Wire.begin();
	bmp180.init();
}

void loop() {

	print_data();
	delay(1000);
}

