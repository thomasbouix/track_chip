#include <stdlib.h>
#include <string.h>
#include <WiFi.h>
#include <SPI.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#include <BMP180I2C.h>
#include "GROVE11302.h"
#include <Wisol.h>

#define NB_ADRESSE_MAC 2
#define TAILLE_ADRESSE_MAC 6

Wisol w = Wisol();

String   mac_address[NB_ADRESSE_MAC];
int      recep_power[NB_ADRESSE_MAC];

uint8_t mac_int[TAILLE_ADRESSE_MAC];

uint8_t bssidtab[NB_ADRESSE_MAC][TAILLE_ADRESSE_MAC];

void get_bssid(int a);
String create_message1();
String create_message2();
String create_message3();
void chose_message_to_send();
float get_altitude();
void wifi_scan();                                                                                                                                                                                                                

void setup() {

	Serial.begin(115200); 
	//while (!Serial); 

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
                                                                                
  Wire.begin();   

	for(int i=0; i++; i<2) {
		for(int j = 0; j++ ;j<6){
			bssidtab[i][j] = (uint8_t)15;
		}
	}
}

void loop() {
  wifi_scan();
  chose_message_to_send();
  delay(1000*60*5);
}

void chose_message_to_send() {

  String temp="17364ABC93C743974A61";

  if(false) {
    temp = create_message3();
    Serial.println(temp);
    Wisol::send_string_data(temp);
  } 
  else 
  {
    temp = create_message1();
    temp = Wisol::complete_hexa_bytes(temp, 10);
    Serial.print("temp (msg1) : ");
    Serial.println(temp);
    Wisol::send_string_data(temp);
    
    temp = create_message2();
    temp = Wisol::complete_hexa_bytes(temp, 10);
    Serial.print("temp (msg2) : ");
    Serial.println(temp);
    
    delay(1000*30);
    Wisol::send_string_data(temp);
  }
}

void get_bssid(int a) {
  Serial.println("get_bssid()");

	for(int i = 0; i < TAILLE_ADRESSE_MAC ;i++)
	{
		mac_int[i] = bssidtab[a][i];
		Serial.print(mac_int[i]);
		Serial.print("-");
	}
	Serial.println("");
}

String create_message1(){
  Serial.println("deb create_message1");
	char temp[2];
  get_bssid(0);
	uint8_t* mac1_addr = mac_int;
 
  //uint8_t mac1_addr[6] = {15, 15, 15, 32, 15, 15};
	int mac1_power = (-1) * recep_power[0];
  Serial.print("mac1_power : ");
  Serial.println(mac1_power);
  
	int altitude = (int)(get_altitude());
  Serial.print("altitude : ");
  Serial.println(altitude);
  altitude = 50;
	
	String res = "";
  
  //AUTH
  String auth = "01";
  res += auth;

  //PUISSANCE
  res+= String(mac1_power);
  
	for (int i = 0; i <TAILLE_ADRESSE_MAC;i++){
		Serial.print(mac1_addr[i]);
		sprintf(temp,"%X",mac1_addr[i]);
    String tmp = String(temp);
    res += Wisol::complete_hexa_bytes(tmp, 1);
    Serial.print(" -- ");
    Serial.println(mac_int[i]);
	}
	res+= String(altitude, HEX);
	
  Serial.println("fin create_message1");
	return res;
}

String create_message2(){
	Serial.println("deb create_message2");
  char temp[2];
  get_bssid(1);
  uint8_t* mac2_addr = mac_int;
 
  //uint8_t mac2_addr[6] = {15, 15, 15, 32, 15, 15};
  int mac2_power = (-1) * recep_power[1];
  Serial.print("mac2_power : ");
  Serial.println(mac2_power);
  
  int altitude = (int)(get_altitude());
  Serial.print("altitude : ");
  Serial.println(altitude);
  altitude = 50;
  
  String res = "";
  
  //AUTH
  String auth = "02";
  res += auth;

  //PUISSANCE
  res+= String(mac2_power);
  
  for (int i = 0; i <TAILLE_ADRESSE_MAC;i++){
    Serial.print(mac2_addr[i]);
    sprintf(temp,"%X",mac2_addr[i]);
    String tmp = String(temp);
    res += Wisol::complete_hexa_bytes(tmp, 1);
    Serial.print(" -- ");
    Serial.println(mac_int[i]);
  }
  res+= String(altitude, HEX);
  
  Serial.println("fin create_message2");
  return res;
}

String create_message3(){
	int prec = 5;
	String res;
	String trame = "$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";//trackChip.get_position();
	int lat_angle, lat_minute; 
	double lat_seconde;
	char lat_c;
	int lng_angle,lng_minute;
	double lng_seconde;
	char lng_c;
	int altitude = get_altitude();
	res+=String(altitude,HEX);
	Wisol::trame_GPGGA_to_DMS(trame, &lat_angle, &lat_minute, &lat_seconde, &lat_c, &lng_angle, &lng_minute, &lng_seconde,  &lng_c);
	res+= Wisol::dms_lat_to_trame_hexa(lat_c, lat_angle, lat_minute, lat_seconde,prec);
	res+= Wisol::dms_lng_to_trame_hexa(lng_c, lng_angle, lng_minute, lng_seconde,prec);
	res+=String(3);
	return res;
}

float get_altitude() {                                                                                                                                                                                                                                       
        static BMP180I2C bmp = BMP180I2C(BMP_I2C_ADDRESS);                                                                                                                                                                                                                                                                                                                                                                      
        bmp.init();                                                                                                                                                                                                                                                                        
                                                                                                                                              
        return bmp.computeAltitude();                                                                                                                 
} 

void wifi_scan() {
  
  Serial.println("scan start");
    
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
          if(bssid_str[9] == 'B' && bssid_str[10] == 'D' && wifi_saved < NB_ADRESSE_MAC){

             // Serial.print(power);
             // Serial.print(", ");
             // Serial.print(wifi_saved);
             // Serial.print(", ");

              for(int i = 0; i < TAILLE_ADRESSE_MAC ;i++){
                bssidtab[wifi_saved][i] = bssid[i];
              }
              
              //mac_address[wifi_saved] = bssid_str;
              recep_power[wifi_saved] = power;
              wifi_saved++;// Print SSID, RSSI, BSSID and encryption mode for each network found
          }

          Serial.print(i + 1);
          Serial.print(": ");
          
          Serial.print(WiFi.SSID(i));

          Serial.print(", Power (dBm) :");
          Serial.print(power);
          
          Serial.print(", BSSID: ");
          Serial.println(bssid_str);
          
          delay(10);
    }
    Serial.println("");

    // Wait for 5s before scanning again
    delay(5000);
  }
}
