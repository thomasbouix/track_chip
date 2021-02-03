#ifndef TRACK_CHIP_H
#define TRACK_CHIP_H

#include <Arduino.h>
#include <BMP180I2C.h>
#include <GROVE11302.h>
#include <Wisol.h>


class TrackChip {

	private :
		BMP180I2C * bmp180 	= NULL;
		Wisol * wisol		= NULL;
		GROVE11302 * gps	= NULL;

	public :
		TrackChip();

		float get_altitude();		
		void send_data(String s);

		String get_all_data();
};

#endif
