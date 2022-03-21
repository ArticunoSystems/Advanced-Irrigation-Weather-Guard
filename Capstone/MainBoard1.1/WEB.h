/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <WiFi.h>

const char* ssid     = "Z Islander";
const char* password = "";

void WiFiSetup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int i=0;
  while (WiFi.status() != WL_CONNECTED & i<10) {
    delay(500);
    Serial.print(".");
    i=i+1;
  }
  if (WiFi.status() != WL_CONNECTED){
    Serial.println("\nNo WiFi");
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("\nWiFi connected");
    Serial.println("\nIP address: ");
    Serial.println(WiFi.localIP());
  }
}

void WiFiEnd(){
  Serial.println("Disconnecting Wifi");
  WiFi.disconnect();
  delay(10);
  if (WiFi.status() != WL_CONNECTED){
    Serial.println("");
    Serial.println("Disconnect Success");
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("");
    Serial.println("Disconnect Failed");
  }
}
