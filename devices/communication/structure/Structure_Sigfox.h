/*
Librairie permettant de standardiser l'envoie des données sur sigfox

*/

#include <string> 
#include <math.h> 
using namespace std;
//Define Structure message 
#ifndef MESSAGE_H
#define MESSAGE_H
 
class Message
{
private:
	// Test if a string is valid before sending it
	float latitude;
	float longitude;
	int altitude;
	
 	Message(float latitude, float longitude , int altitude);
 
 	
public:
    Message();
		void set_lat_long(float latitude, float longitude);
		void set_altitude(int altitude);
		string structured_message();
 		static string double_to_hexa(double a, int prec);
 		static string int_to_hexa(int a);
 		static int double_to_int(double a, int prec);
#endif
 };



