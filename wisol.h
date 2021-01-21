#include <HardwareSerial.h>
#include <string>
#include <Arduino.h>

#define RXD2 16
#define TXD2 17




//Define class wisol
#ifndef DATE_H
#define DATE_H
 
class Wisol
{
private:
	// Test if a string is valid before sending it
 Wisol(int baurate, int RX, int TX);
 		
public:
    Wisol();
		void send_string_data(String envoie);
    static bool IsHexCharOrNewLine(char c);
    static bool IsHex(char* text);
    static bool string_ok(String verif);
};
 
#endif
 
