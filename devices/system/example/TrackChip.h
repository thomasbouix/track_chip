#ifndef TRACK_CHIP_H
#define TRACK_CHIP_H

#include <stdlib.h>
#include <string.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#include <BMP180I2C.h>
#include <GROVE11302.h>
#include <Wisol.h>
typedef uint8_t bssid[6];
typedef bssid bssid_tab[2];
class TrackChip {

private :
	GROVE11302 * gps; 

	// Wifi ID
	char * AP_SSID	= "Redmi";
	char * AP_PWD 	= "toto1234";

	// api constexpr_ID 
	char * serverAddress = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyDMnY8W47H_ztdC4sJjo2Z9_bu2y9-zEPM";
	int port = 8080;

	// Wifi scanner var
	String mac_address[3];
	int recep_power[3];
	float location_lat  	= 0;
	float location_lng  	= 0;
	int accuracy			= 0;
	
	//Mac address
	bssid_tab bssidtab;
	
public :
	TrackChip();
	~TrackChip();

	// Peripherals utilities
	void send_data(String s);	// Wisol
	float get_altitude();		// Altimètre
	String get_position();		// GSP

	// Wifi utilities
	void connect_to_wifi();		// Se connecte au wifi	
	void wifi_scan();		// scan les réseaux wifi sans avoir besoin d'y être connecté 
	int send_mac_and_get_pos();	// 

	// Wifi Getters
	int get_wifi_accuracy()	{ return accuracy;	}
	float get_wifi_lat()	{ return location_lat;	}
	float get_wifi_lng()	{ return location_lng;	}
};

#endif
