#include "WEB.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("What is your SSID?: ");
  while (Serial.available() == 0) {
    // wait
  }
  Serial.readBytesUntil(10, ssid, 50);
  Serial.println(ssid);
  Serial.print("What is your Password?: ");
  while (Serial.available() == 0) {
    // wait
  }
  Serial.readBytesUntil(10, password, 50);
  Serial.println(password);

  WiFiSetup();
}

void loop() {
  // put your main code here, to run repeatedly:

}
