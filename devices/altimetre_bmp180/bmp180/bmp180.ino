#include <Wire.h>
#include <SoftwareSerial.h>

int bmp_address = 0xEF;                   // 1110 111(1) ; (last bit = R/W bit)

#define bmp_register0   Ox00              // adresses des registres du périphérique slave 
#define bmp_register1   Ox01              // 

int bmp_reg0, bmp_reg1;

void setup() {
  Serial.begin(9600);                     // Stdout
  Wire.begin();                           // Initiate the Wire library
  
  delay(100);

  /* Transfert de données */
  Wire.beginTransmission(bcm_address);    // Enable measurement
  Wire.write(bmp_reg0);                   // Demande des données aux registres
  Wire.write(bmp_reg1);                   // 
  Wire.endTransmission();                 // Fin de transmission

  /* Traitement des données */
  Wire.requestfrom(bmp_address, 2);       // Demande les données reçues

  if(Wire.available() == 2) {
    bmp_reg0 = Wire.read();
    bmp_reg1 = Wire.read();
  }

  Serial.println("bmp_reg0 = %d", bmp_reg0);
  Serial.println("bmp_reg1 = %d", bmp_reg1);

}

void loop() {
  
  Serial.println("bonjour\n");
  delay(100);

}
