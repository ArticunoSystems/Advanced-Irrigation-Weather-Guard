float z1Flow = 12;
float z2Flow = 10;
float z3Flow = 8;

int fRain0 =0;
int fRain1 =0;

#include "LEAK.h"
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
