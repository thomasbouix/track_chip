#include <Wire.h>
#include <SoftwareSerial.h>

int bmp_address = 0xEF;                   // 1110 111(1) ; (last bit = R/W bit)

#define I2C_SDA 	33
#define I2C_SCL		32
#define bmp_register0   Ox00              // adresses des registres du périphérique slave 
#define bmp_register1   Ox01              // 

int bmp_reg0, bmp_reg1;

void setup() {
  Serial.begin(9600);                     // Stdout
  Wire.begin();                           // Initiate the Wire library
  
  delay(100);

  /* 
   *  Lire la donnée de calibration dans la E2PROM pour pouvoir 
   *  calculer la pression après sa lecture
   */

  /*
   * Mode ultra low-power
   * oversampling_setting = 0 ; temps de conversion max = 4.5 ms
   */

  /* Transfert de données */
  Wire.beginTransmission(bcm_address);    // Enable measurement
  Wire.write(bmp_reg0);                   // Demande des données aux registres
  Wire.write(bmp_reg1);                   // 
  Wire.endTransmission();                 // Fin de transmission

  /* Traitement des données */
  Wire.requestfrom(bmp_address, 2);       // Demande les données reçues

  if(Wire.available() >= 2) {
    bmp_reg0 = Wire.read();
    bmp_reg1 = Wire.read();
  }

  Serial.println("bmp_reg0 = %d", bmp_reg0);
  Serial.println("bmp_reg1 = %d", bmp_reg1);

}

void loop() {
  
}

uint16_t read_temperature_value() {
  /*
      write 0x2E into reg 0xF4, wait 4.5ms
      read reg 0xF6 (MSB), 0xF7 (LSB)
      UT = MSB << 8 + LSB
   */
  Wire.write(
}


uint32_t read_pressure_value() {
  /*
     write 0x34+(oss<<6) into reg 0XF4, wait
     read reg 0xF6 (MSB), 0xF7 (LSB), 0xF8 (XLSB)
     UP = (MSB<<16 + LSB<<8 + XLSB) >> (8-oss) 
   */
}

void calculate_true_pressure() {
  X1 = 

}
