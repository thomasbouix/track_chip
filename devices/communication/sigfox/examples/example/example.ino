#include "Wisol.h"
String retour;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wisol w;
  Serial.println("end setup");
  String res = "00100";
  w.send_string_data(res);
}

void loop() {
  // put your main code here, to run repeatedly:
     while (Serial2.available()>0) {
    retour = Serial2.readStringUntil('\n');
    Serial.println(retour);
  }

}
