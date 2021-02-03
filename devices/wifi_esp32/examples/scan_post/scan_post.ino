#include <WiFi.h>

#include <HTTPClient.h>

#include <ArduinoJson.h>
 
char *AP_SSID = "Redmi";
char *AP_PWD = "toto1234";

const char  *serverAddress = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyDMnY8W47H_ztdC4sJjo2Z9_bu2y9-zEPM";
int         port = 8080;

String mac_address[3];
int    recep_power[3];

void setup()
{
    Serial.begin(115200);
    
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

    run();
}

void loop()
{}

void run()
{
    wifi_scan();

    if(postDataToServer() == -1){
      Serial.println("Error post data");
    }
}

int postDataToServer() {
 
  Serial.println("Posting JSON data to server...");

  // Block until we are able to connect to the WiFi access point
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;   
     
    http.begin(serverAddress);  
    http.addHeader("Content-Type", "application/json");           
     
    StaticJsonDocument<256> doc;

    doc["considerIp"] = "false";

    JsonArray wifiAccessPoints = doc.createNestedArray("wifiAccessPoints");

    Serial.println("Filling Json with first wifi object...");
    Serial.println("macAdress : " + mac_address[0]);
    Serial.println("Strength  : " + recep_power[0]);
    
    JsonObject wifiAccessPoints_0           = wifiAccessPoints.createNestedObject();
    wifiAccessPoints_0["macAddress"]        = mac_address[0];
    wifiAccessPoints_0["signalStrength"]    = recep_power[0];

    delay(1000);

    Serial.println("Filling Json with second wifi object...");
    Serial.println("macAdress : " + mac_address[1]);
    Serial.println("Strength  : " + recep_power[1]);
    
    JsonObject wifiAccessPoints_1           = wifiAccessPoints.createNestedObject();
    wifiAccessPoints_1["macAddress"]        = mac_address[1];
    wifiAccessPoints_1["signalStrength"]    = recep_power[1];

    delay(1000);

    Serial.println("Filling Json with third wifi object...");
    Serial.println("macAdress : " + mac_address[2]);
    Serial.println("Strength  : " + recep_power[2]);
    
    JsonObject wifiAccessPoints_2           = wifiAccessPoints.createNestedObject();
    wifiAccessPoints_2["macAddress"]        = mac_address[2];
    wifiAccessPoints_2["signalStrength"]    = recep_power[2];

    delay(1000);
     
    String requestBody;
    serializeJson(doc, requestBody);
     
    int httpResponseCode = http.POST(requestBody);

    while(true){
        if(httpResponseCode>0){
           
          String response = http.getString();                       
           
          Serial.println(httpResponseCode);   
          Serial.println(response);
         
          return 0;
      }
      else {
       
        Serial.printf("Error occurred while sending HTTP POST");
        return -1;
      }
    }
  }

  return -1;
}

void wifi_scan(){
    
    Serial.println("scan start");
    
    int wifi_saved = 0;

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        
        for (int i = 0; i < n; ++i) {
            
            // Print SSID and RSSI for each network found

            // if wifi isn't mobile
//            if(int(WiFi.encryptionType(i)) != 3 && wifi_saved < 3){
//                mac_address[wifi_saved] = WiFi.BSSID(i);
//                recep_power[wifi_saved] = int(WiFi.RSSI(i));
//            }
            
            Serial.print(i + 1);
            Serial.print(": ");
            
            Serial.print(WiFi.SSID(i));

            Serial.print(", Power (dBm) :");
            Serial.print(WiFi.RSSI(i));
            
            Serial.print(", MAC : ");
            byte bssid[6];
            WiFi.BSSID(bssid);    
            Serial.print("BSSID: ");
            Serial.print(bssid[5],HEX);
            Serial.print(":");
            Serial.print(bssid[4],HEX);
            Serial.print(":");
            Serial.print(bssid[3],HEX);
            Serial.print(":");
            Serial.print(bssid[2],HEX);
            Serial.print(":");
            Serial.print(bssid[1],HEX);
            Serial.print(":");
            Serial.println(bssid[0],HEX);
            
            Serial.print(", authmode : ");
            Serial.print(WiFi.encryptionType(i));
            
            delay(10);
        }
    }
    Serial.println("");

    // Wait for 5s before scanning again
    delay(5000);
}
