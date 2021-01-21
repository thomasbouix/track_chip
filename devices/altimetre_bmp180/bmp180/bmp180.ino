#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include "BMP180I2C.h"

/*
 * PIN I2C 
 * SDA = D21, PIN 42
 * SCL = D22, PIN 39
 */

#define BMP_I2C_ADDRESS 0x77                  // 1110 111(1) ; (last bit = R/W bit)

// create an BMP180 object using the I2C interface
BMP180I2C bmp180(BMP_I2C_ADDRESS);  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //wait for serial connection to open (only necessary on some boards)
  while (!Serial);

  Wire.begin();

  //begin() initializes the interface, checks the sensor ID and reads the calibration parameters.  
  if (!bmp180.begin())
  {
    Serial.println("begin() failed. check your BMP180 Interface and I2C Address.");
      
    while (1);
  }

  //reset sensor to default parameters.
  bmp180.resetToDefaults();

  //enable ultra high resolution mode for pressure measurements
  bmp180.setSamplingMode(BMP180MI::MODE_UHR);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(1000);

  //start a temperature measurement
  if (!bmp180.measureTemperature())
  {
    Serial.println("could not start temperature measurement, is a measurement already running?");
    return;
  }

  //wait for the measurement to finish. proceed as soon as hasValue() returned true. 
  do
  {
    delay(100);
  } while (!bmp180.hasValue());

  float temperature = bmp180.getTemperature();

  //start a pressure measurement. pressure measurements depend on temperature measurement, you should only start a pressure 
  //measurement immediately after a temperature measurement. 
  if (!bmp180.measurePressure())
  {
    Serial.println("could not start perssure measurement, is a measurement already running?");
    return;
  }

  //wait for the measurement to finish. proceed as soon as hasValue() returned true. 
  do
  {
    delay(100);
  } while (!bmp180.hasValue());

  float P = bmp180.getPressure();

  float altitude = - 8.3143 * 288.15 * log(P/101325) / (0.02896 * 9.807) - 155;

  Serial.print("altitude : ");
  Serial.print(altitude);
  Serial.println("m");  
}
