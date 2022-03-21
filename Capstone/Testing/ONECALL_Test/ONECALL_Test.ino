#include <WiFi.h>
#include "ONECALL.h"

//----WiFi Settings----
#define ssid "Z Islander"
#define password ""

void WiFiSetup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void setup(){
  WiFiSetup();
  OneCallLoop();
}

void loop(){
  
}
