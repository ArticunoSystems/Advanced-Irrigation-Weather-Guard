#include "TEMP.h"

void setup(){
  Serial.begin(115200);
}

void loop(){
  int Temp;
  Temp = TempLoop();
  Serial.println(Temp);
}
