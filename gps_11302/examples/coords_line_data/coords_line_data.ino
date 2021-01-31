#define RX2 16                                  // Port RX 2 => GPIO 16 => PIN 25
#define TX2 17                                  // Port TX 2 => GPIO 17 => PIN 27

unsigned char header[5];                        // NMEA headers, Example : $GPGGA
unsigned char buf[70];                          // NMEA data, Example:  ,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47  

void clearBufferArray(unsigned char *arr, int count);
  
void setup()
{
    Serial.begin(115200);                          // the Serial port of Arduino baud rate => Communication between ESP and computer via USB port.
    Serial2.begin(9600);                           // Hardware Serial Port 2 => Communication between ESP and GPS
}
 
void loop()
{  

  clearBufferArray(buf, 70);
  clearBufferArray(header, 5);

  while (Serial2.available()){
    
    if(char(Serial2.read()) == '$'){
      
      for(int i = 0; i < 5; i++){
        header[i] = char(Serial2.read());          // on recupere le header de la ligne; $...
      }

      Serial.print("header : ");
      Serial.write(header, 5);
      Serial.print("\n");

      if ((header[0] == 'G') & (header[1] == 'P') & (header[2] == 'G') & (header[3] == 'G') & (header[4] == 'A')) {
        
        for(int i = 0 ; i < 70 ; i++){
             
            buf[i] = char(Serial2.read());           // on remplit le buffer avec une ligne de donnée
            
            if(buf[i] == '$'){break;}
        }
        
        Serial.print("\n=============\n");
        Serial.print("buffer : "); 
        Serial.write(buf, 70);
        Serial.print("\n=============\n"); 
  
      }
    }
    delay(100);
  } 
}

void clearBufferArray(unsigned char *arr, int count)   // function to clear buffer array
{
    for (int i = 0 ; i < count ; i++) {
        arr[i] = NULL;                                 // clear all index of array with command NULL
    }                                        
}
