int fTemp1 = 35;
int fTemp2 = 40;
int fTemp3 = 40;
int z1Temp = 40;
int z2Temp = 40;
int z3Temp = 40;

#include "PURGE.h"

void setup() {
  Serial.begin(115200);
  PurgeSetup();
  //digitalWrite(waterMain,HIGH);
  //digitalWrite(z1Valve,HIGH);
  //digitalWrite(z2Valve,HIGH);
  //digitalWrite(z3Valve,HIGH);
  //digitalWrite(airMain,HIGH);
  //digitalWrite(airPower,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  if(purgeState ==2){
    purgeState=0;
  }
  PurgeCheck();
}
