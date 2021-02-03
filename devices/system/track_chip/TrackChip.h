#ifndef TRACK_CHIP_H
#define TRACK_CHIP_H

#include <Arduino.h>
#include <BMP180I2C.h>
#include <GROVE11302.h>
#include <Wisol.h>


class TrackChip {

	public :
		TrackChip();
		~TrackChip();

		float get_altitude();		
		void send_data(String s);
		String get_position();	
};

#endif
