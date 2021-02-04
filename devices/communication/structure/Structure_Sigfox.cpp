#include "Structure_Sigfox.h"

//Constructor
Message::Message() {
	this->latitude = 0;
	this->longitude = 0;
	this->altitude = 0;
}

Message::Message(float latitude, float longitude , int altitude){
	this->latitude = latitude;
	this->longitude = longitude;
	this->altitude = altitude;
}


//private function
	 string Message::float_to_hexa(float a){
		string message = "AA";
		return message;
	}
 	 string int_to_hexa(int a){
 		string message = "AA";
		return message;
 	}


//public function
void Message::set_lat_long(float latitude, float longitude){
	this->latitude = latitude;
	this->longitude = longitude;
}

void Message::set_altitude(int altitude){
	this->altitude = altitude;
}

string Message::structured_message(){
		string message = "Hello";
		return message;
}
