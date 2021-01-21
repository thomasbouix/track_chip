//Multi interface Bosch Sensortec BMP180  pressure sensor library 
// Copyright (c) 2018-2019 Gregor Christandl <christandlg@yahoo.com>
// home: https://bitbucket.org/christandlg/BMP180mi
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#include "BMP180I2C.h"

BMP180I2C::BMP180I2C(uint8_t address) :
	BMP180TwoWire(&Wire, address)
{
}

BMP180I2C::~BMP180I2C()
{
}

// Fonction ajoutée par Thomas Bouix
float BMP180I2C::computeAltitude() {
	
	if (!this->measureTemperature()) {
		Serial.println("could not start temperature measurement!");
	       	Serial.println("Is a measurement already running?");
		return;
	}

	// wait for the measurement to finish. proceed as soon as hasValue() returned true. 
	do {
		delay(100);
	} while (!this->hasValue());

	float temperature = this->getTemperature();

	// start a pressure measurement. 
	// pressure measurements depend on temperature measurement,
	// you should only start a pressure 
	// measurement immediately after a temperature measurement. 
	if (!this->measurePressure()) {
		Serial.println("could not start perssure measurement");
		Serial.println("is a measurement already running?");
		return;
	}

	//wait for the measurement to finish. proceed as soon as hasValue() returned true. 
	do {
		delay(100);
	} while (!this->hasValue());

	float P = this->getPressure();

	float altitude = - 8.3143 * 288.15 * log(P/101325) / (0.02896 * 9.807) - 155;

	return altitude;
}
