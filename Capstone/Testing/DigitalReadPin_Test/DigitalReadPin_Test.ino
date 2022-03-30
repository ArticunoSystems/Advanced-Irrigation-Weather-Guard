#include "PIN.h"

void setup() {
  Serial.begin(115200);
  DPinSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  DPinLoop();
}
