/*
Librairie permettant d'envoyer une chaine de caractère de 12 octets d'un ESP32 vers un module Sigfox Wisol
Utilise les pins RX2, TX2 par défaut pour communiquer

*/
#include <HardwareSerial.h>
#include <string>
#include <Arduino.h>

#define RX2 16		// Port RX 2 => GPIO 16 => PIN 25
#define TX2 17		// Port TX 2 => GPIO 17 => PIN 27

//Define class wisol
#ifndef WISOL_H
#define WISOL_H
 
class Wisol {

	private:
		// Test if a string is valid before sending it
		Wisol(int baurate, int RX, int TX);
			
	public:
		Wisol();

		static bool IsHexCharOrNewLine(char c);
		static bool IsHex(char* text);
		static bool string_ok(String verif);

		void send_string_data(String envoie);
};
 
#endif
 
