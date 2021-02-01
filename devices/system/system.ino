#include <Arduino.h>
#include <BMP180I2C.h>
#include <GROVE11302.h>

#define BMP_I2C_ADDRESS 0x77 

BMP180I2C bmp180(BMP_I2C_ADDRESS);
GROVE11302 gps_grove();

float altitude;

void setup() {

	Serial.begin(115200); 
	while (!Serial);

	Wire.begin();

	bmp180.init();

}

void loop() {

	altitude = bmp180.computeAltitude();
  // gps_grove.get_line_data();

  Serial.print("\n=============\n");
  Serial.print("buffer : "); 
  // Serial.write(gps_grove.buffer, 70);
	Serial.print("altitude : ");
	Serial.print(altitude);
	Serial.println("m");	
  Serial.print("\n=============\n");

	delay(1000);

}
