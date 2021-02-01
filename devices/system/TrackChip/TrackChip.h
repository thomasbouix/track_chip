#ifndef TRACK_CHIP_H
#define TRACK_CHIP_H

#include <Arduino.h>
#include <BMP180I2C.h>
#include <GROVE11302.h>
#include <Wisol.h>

#define BMP_I2C_ADDRESS 0x77 

class TrackChip {

	private :
		BMP180I2C * bmp180;
		GROVE11302 * gps_grove;
		Wisol * w;

	public :
		TrackChip();

		float get_altitude();		
		void send_data(String s);

		String get_all_data();
};

#endif
