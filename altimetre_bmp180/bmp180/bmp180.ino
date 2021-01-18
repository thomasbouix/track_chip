#include <Wire.h>

int bcm_address = 0xEF;   // 1110 111(1); avec bit entre parenthèses le bit de lecture/ecriture

void setup() {
  Serial.begin(9600);     // stdin
  Wire.begin();           // Initiate the Wire library
  
  delay(100);
  
  Wire.beginTransmission(ADXLAddress);    // Enable measurement
  Wire.write(Power_Register);
  Wire.write(8);                          // Bit D3 High for measuring enable (0000 1000)
  Wire.endTransmission();

}

void loop() {
  // put your main code here, to run repeatedly:

}
