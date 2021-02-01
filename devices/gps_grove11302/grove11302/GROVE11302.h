#ifndef GROVE11302_H_
#define GROVE11302_H_

#include <Arduino.h>

#define RX2 16              	// Port RX 2 => GPIO 16 => PIN 25
#define TX2 17                  // Port TX 2 => GPIO 17 => PIN 27

class GROVE11302
{
public:
	
	unsigned char buffer[70];	// NMEA data, Example:  ,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47  

	GROVE11302();
	GROVE11302(int baudrate, int RX, int TX);
	virtual ~GROVE11302();

	// Fill buffer attribute with NMEA data
	void get_data_line();

	void clearBufferArray(unsigned char *arr, int count);
};

#endif
