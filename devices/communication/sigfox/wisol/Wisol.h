/*
Librairie permettant d'envoyer une chaine de caractère de 12 octets d'un ESP32 vers un module Sigfox Wisol
Utilise les pins RX2, TX2 par défaut pour communiquer

*/
#include <HardwareSerial.h>
#include <string>
#include <Arduino.h>
#include <math.h>
#define RXD2 16
#define TXD2 17

//Define class wisol
#ifndef WISOL_H
#define WISOL_H
 
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
    
    //New function
   static String double_to_hexa(double a, int prec);
 	static String int_to_hexa(int a);
 	static int double_to_int(double a, int prec);
 	
 	static double Dms_to_dd(char cardinal, int angle, int minute, double seconde);
 	static double shift_latitude(double lat);
 	static double shift_longitude(double lng);
 	static String complete_hexa_bytes(String hexa, int nb_bytes);
 	static String dms_lat_to_trame_hexa(char cardinal, int angle, int minute, double seconde,int prec);
 	static String dms_lng_to_trame_hexa(char cardinal, int angle, int minute, double seconde,int prec);
 	static String altitude_to_trame_hexa(int altitude);
};
 
#endif
 
