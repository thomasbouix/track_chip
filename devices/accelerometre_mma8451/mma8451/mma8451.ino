#include <Wire.h>
#include "Adafruit_MMA8451.h"

#define MMA_I2C_ADDRESS 0x1D

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup(void) {
  Serial.begin(115200);
  
  Serial.println("Test - Adafruit MMA8451");
  
  if (!mma.begin(MMA_I2C_ADDRESS)) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");
  
}

void loop() {
  sensors_event_t event; 
  mma.getEvent(&event);
  
  Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.println("m/s^2 ");
  
  Serial.println();
  delay(500);
}
