#include <Arduino.h>
#include <BMP180I2C.h>

#define BMP_I2C_ADDRESS 0x77 
BMP180I2C bmp180(BMP_I2C_ADDRESS); 
float altitude;

void setup() {

	Serial.begin(115200); 
	while (!Serial);

	Wire.begin();

	bmp180.init();

}

void loop() {

	altitude = bmp180.computeAltitude();

	Serial.print("altitude : ");
	Serial.print(altitude);
	Serial.println("m");	

	delay(1000);

}
