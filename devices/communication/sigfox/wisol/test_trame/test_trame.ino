#include "Wisol.h"
void setup() {
  // put your setup code here, to run once:
  //Wisol w;
  Serial.begin(115200);
  //Serial.println(w.verif_type("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E"));
  
}

void loop() {
  // put your main code here, to run repeatedly:
 Wisol w;
 if( w.verif_type("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E")) {
  Serial.println("GPGGA");
  }
  Serial.println("sleep:");
  delay(3000);
}
