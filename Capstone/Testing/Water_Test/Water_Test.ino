int fRain0 =0;
int fRain1 =0;

#include "WATER.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WaterSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  WaterCheck();
}
