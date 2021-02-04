#include "Structure_Sigfox.h"
#include <iostream>
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


//public function
	 string Message::double_to_hexa(double a, int prec){
		string message = "";
		int temp;
		temp = double_to_int(a, prec);
		message = int_to_hexa(temp);
		return message;
	}
 	 string Message::int_to_hexa(int a){
 		char hex_string[20];
   sprintf(hex_string, "%X", a); //convert number to hex
   return hex_string;
 	}


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

int Message::double_to_int(double a, int prec){
	int res = round(a*pow (10, prec));
	//std::cout << res<<std::endl;
	return res;
}

