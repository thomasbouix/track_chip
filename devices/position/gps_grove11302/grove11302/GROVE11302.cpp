#include "GROVE11302.h"

// Constructor
GROVE11302::GROVE11302(int baudrate, int RX, int TX){
	Serial2.begin(baudrate, SERIAL_8N1, RX, TX);		// Hardware Serial Port 2 => Communication between ESP and GPS
}

GROVE11302::GROVE11302(){

	GROVE11302(9600, RX0, TX0);	// Hardware Serial Port 2 => Communication between ESP and GPS
}

void GROVE11302::get_data_line(){

	unsigned char header[5];	// NMEA headers, Example : $GPGGA

	clearBufferArray(buffer, 70);
	clearBufferArray(header, 5);

 	while (Serial2.available()){
	    
		if(char(Serial2.read()) == '$'){
		      
			for(int i = 0; i < 5; i++){
				header[i] = char(Serial2.read());          // on recupere le header de la ligne; $...
			}

			if ((header[0] == 'G') & (header[1] == 'P') & (header[2] == 'G') & (header[3] == 'G') & (header[4] == 'A')) {
				
				for(int i = 0 ; i < 70 ; i++){
					buffer[i] = char(Serial2.read());           // on remplit le buffer avec une ligne de donnée
					if(buffer[i] == '$') {break;}
				}  
			}
		}
 	}
}

void GROVE11302::clearBufferArray(unsigned char *arr, int count)   // function to clear buffer array
{
	for (int i = 0 ; i < count ; i++) {
		arr[i] = NULL;                                 // clear all index of array with command NULL
	}                                        
}

