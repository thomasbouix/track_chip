
// PIN D18 et D19
int D18 = 18;
int D19 = 19;

unsigned char buffer[64];                           // buffer array for data receive over serial port
int count=0;                                        // counter for buffer array
  
void setup()
{
    Serial.begin(115200);                           // the Serial port of Arduino baud rate.
}
 
void loop()
{
        Serial.print("D18 : ");
        Serial.print(digitalRead(D18));
        Serial.print("\n");

        Serial.print("D19 : ");
        Serial.print(digitalRead(D19));
        Serial.print("\n");
 
        /*buffer[count++]=;      // writing data into array
        if(count == 64)break;
 
        clearBufferArray();                         // call clearBufferArray function to clear the stored data from the array
        count = 0;*/                                  // set counter of while loop to zero 
}
 
 
void clearBufferArray()                             // function to clear buffer array
{
    for (int i=0; i<count;i++)
    {
        buffer[i]=NULL;
    }                                               // clear all index of array with command NULL
}
