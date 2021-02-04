#include <GROVE11302.h>

GROVE11302 gps_grove = GROVE11302();

void setup()
{
  Serial.begin(115200);                         // the Serial port of Arduino baud rate => Communication between ESP and computer via USB port.
}
 
void loop()
{  
  gps_grove.get_data_line();

  Serial.print("\n=============\n");
  Serial.print("buffer : "); 
  Serial.write(gps_grove.buffer, 70);
  Serial.print("\n=============\n");

  delay(1000);
}
