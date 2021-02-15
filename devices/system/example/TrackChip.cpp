#include "TrackChip.h"

TrackChip::TrackChip() {
	// Inutile de print ici, la liaison série est initialisée plus tard
	this->gps = new GROVE11302();
	Wire.begin();
	AP_SSID	= "Redmi";
	AP_PWD 	= "toto1234";
}

TrackChip::~TrackChip() {}

void TrackChip::send_data(String s) {
	// Envoyer uniquement des chaines de la forme :
	// 004A882F000398DC2F 

	// insérer vérification

	Wisol wisol = Wisol();
	wisol.send_string_data(s);
}

float TrackChip::get_altitude() {
	static bool init = true; 
	static BMP180I2C bmp = BMP180I2C(BMP_I2C_ADDRESS);

	if (init) {
		bmp.init();
		init = false;
	}

	return bmp.computeAltitude();
}

String TrackChip::get_position() {
	gps->get_data_line();
	String res = (char*) (gps->buffer);

	return res;
}

void TrackChip::connect_to_wifi() {
	Serial.println("connection_to_wifi...");
	Serial.println(AP_SSID);
	Serial.println(AP_PWD);
	
	WiFi.begin(AP_SSID, AP_PWD);
	
	Serial.println("Connecting");
	while(WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	
	Serial.println("");
	Serial.print("Connected to WiFi network with IP Address: ");
	Serial.println(WiFi.localIP());
	Serial.println("Setup done");
}

void TrackChip::wifi_scan() {
	Serial.println("Starting scan");
	int wifi_saved = 0;
	uint8_t *bssid;
	char bssid_str[18];
	int power;

	// WiFi.scanNetworks will return the number of networks found
	int n = WiFi.scanNetworks();
	Serial.println("scan done");

	if (n == 0) {
		Serial.println("no networks found");
	} else {
		Serial.print(n);
		Serial.println(" networks found");

		for (int i = 0; i < n; ++i) {
			
			bssid = WiFi.BSSID(i);
			sprintf(bssid_str, "%X-%X-%X-%X-%X-%X",bssid[5], bssid[4], bssid[3], bssid[2], bssid[1], bssid[0]); 
			power = int(WiFi.RSSI(i));
			
			// select fix WiFi which are in google database
			if(bssid_str[9] == 'B' && bssid_str[10] == 'D' && wifi_saved < 3){
				// Serial.print(power);
				// Serial.print(", ");
				// Serial.print(wifi_saved);
				// Serial.print(", ");
				mac_address[wifi_saved] = bssid_str;
				recep_power[wifi_saved] = power;
				for(int j = 0; j++ ;j<5){
				  bssidtab[wifi_saved][j] = bssid[5-j];
				}
				wifi_saved++;
			}

			// Print SSID, RSSI, BSSID and encryption mode for each network found
			Serial.print(i + 1);
			Serial.print(": ");
			Serial.print(WiFi.SSID(i));
			Serial.print(", Power (dBm) :");
			Serial.print(power);
			Serial.print(", BSSID: ");
			Serial.println(bssid_str);
			
			delay(10);
		}
		delay(5000);	 // Wait for 5s before scanning again
	}
}	

int TrackChip::send_mac_and_get_pos() {
	Serial.println("Posting JSON data to server...");
	
	// Block until we are able to connect to the WiFi access point
	if (WiFi.status() == WL_CONNECTED) {
	
		HTTPClient http;	 
		 
		http.begin(serverAddress);	
		http.addHeader("Content-Type", "application/json");					 
		 
		StaticJsonDocument<256> req;
	
		JsonArray wifiAccessPoints = req.createNestedArray("wifiAccessPoints");

		Serial.println("Filling Json with first wifi object...");
		Serial.println("macAdress : " + mac_address[0]);
		Serial.print("Strength	: ");
		Serial.println(recep_power[0]);
		
		JsonObject wifiAccessPoints_0				= wifiAccessPoints.createNestedObject();
		wifiAccessPoints_0["macAddress"]			= mac_address[0];
		wifiAccessPoints_0["signalStrength"]		= recep_power[0];
		wifiAccessPoints_0["signalToNoiseRatio"]    = 0;

		delay(1000);

		Serial.println("Filling Json with second wifi object...");
		Serial.println("macAdress : " + mac_address[1]);
		Serial.print("Strength	: ");
		Serial.println(recep_power[1]);
		
		JsonObject wifiAccessPoints_1				= wifiAccessPoints.createNestedObject();
		wifiAccessPoints_1["macAddress"]			= mac_address[1];
		wifiAccessPoints_1["signalStrength"]		= recep_power[1];
		wifiAccessPoints_0["signalToNoiseRatio"]    = 0;

		delay(1000);

		Serial.println("Filling Json with third wifi object...");
		Serial.println("macAdress : " + mac_address[2]);
		Serial.print("Strength	: ");
		Serial.println(recep_power[2]);
		
		JsonObject wifiAccessPoints_2				= wifiAccessPoints.createNestedObject();
		wifiAccessPoints_2["macAddress"]			= mac_address[2];
		wifiAccessPoints_2["signalStrength"]		= recep_power[2];
		wifiAccessPoints_0["signalToNoiseRatio"]    = 0;

		delay(1000);
		 
		String requestBody;
		serializeJson(req, requestBody);

		Serial.println("");
		Serial.print(requestBody);
		Serial.println("");
		 
		int httpResponseCode = http.POST(requestBody);

		while(true) {
			if(httpResponseCode>0){
				 
				String response = http.getString(); 

				Serial.println(httpResponseCode);	 
				Serial.println(response);

				// Parse Json response File and get lat, lng and accuracy
				StaticJsonDocument<128> res;
				deserializeJson(res, response);

				location_lat = res["location"]["lat"];
				location_lng = res["location"]["lng"];

				accuracy = res["accuracy"];
				accuracy = accuracy / 50;
				
				return 0;
			} else {
				Serial.printf("Error occurred while sending HTTP POST");
				return -1;
			}
		}
	}

	return -1;
}
