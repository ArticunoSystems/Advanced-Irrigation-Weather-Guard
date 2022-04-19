
#include "BTTN.h"

void setup() {
  Serial.begin(115200);
  BTTNSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("current level: ");
  Serial.println(curlvl);
  Serial.print("level 1: ");
  Serial.println(lvl1);
  Serial.print("level 2: ");
  Serial.println(lvl2);
  Serial.print("level 3: ");
  Serial.println(lvl3);
  Serial.print("level 4: ");
  Serial.println(lvl4);
  Serial.println();
  BTTNLoop();
  delay(10);
}
