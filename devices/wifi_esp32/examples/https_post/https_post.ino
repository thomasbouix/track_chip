#include <ArduinoJson.h>
#include <HTTPClient.h>
#include "WiFiMulti.h"
 
const char *AP_SSID = "Redmi";
const char *AP_PWD = "toto1234";
  
WiFiMulti wifiMulti;
 
void setup() {
  Serial.begin(115200);
   
  delay(4000);
  wifiMulti.addAP(AP_SSID, AP_PWD);
 
  postDataToServer();
}
 
void loop() {
  // Not used in this example
}
 
void postDataToServer() {
 
  Serial.println("Posting JSON data to server...");

  // Block until we are able to connect to the WiFi access point
  if (wifiMulti.run() == WL_CONNECTED) {
     
    HTTPClient http;   
     
    http.begin("https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyDMnY8W47H_ztdC4sJjo2Z9_bu2y9-zEPM");  
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<256> doc;

    doc["considerIp"] = "false";

    JsonArray wifiAccessPoints = doc.createNestedArray("wifiAccessPoints");

    JsonObject wifiAccessPoints_0 = wifiAccessPoints.createNestedObject();
    wifiAccessPoints_0["macAddress"] = "70:62:B8:51:26:20";
    wifiAccessPoints_0["signalStrength"] = -57;
    wifiAccessPoints_0["signalToNoiseRatio"] = 0;

    JsonObject wifiAccessPoints_1 = wifiAccessPoints.createNestedObject();
    wifiAccessPoints_1["macAddress"] = "EA:A6:98:D0:A1:BA";
    wifiAccessPoints_1["signalStrength"] = -58;
    wifiAccessPoints_1["signalToNoiseRatio"] = 0;
     
    String requestBody;
    serializeJson(doc, requestBody);
     
    int httpResponseCode = http.POST(requestBody);
 
    if(httpResponseCode>0){
       
      String response = http.getString();                       
       
      Serial.println(httpResponseCode);   
      Serial.println(response);
     
    }
    else {
     
      Serial.printf("Error occurred while sending HTTP POST: %s\n", httpClient.errorToString(statusCode).c_str());
       
    }
     
  }
}
