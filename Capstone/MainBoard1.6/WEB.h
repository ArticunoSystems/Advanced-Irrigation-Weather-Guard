#include <WiFi.h>
//const char* ssid = "Z Islander"; //Z Islander
//const char* password = ""; //z Islander

const char* ssid = "MyAltice 5b1299"; //Nathan's
const char* password = "61-linen-3480"; //Nathan's

void WiFiSetup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int i=0;
  while (WiFi.status() != WL_CONNECTED & i<20) {
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
  delay(100);
  if (WiFi.status() != WL_CONNECTED){
    Serial.println("");
    Serial.println("Disconnect Success");
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("");
    Serial.println("Disconnect Failed");
  }
}
