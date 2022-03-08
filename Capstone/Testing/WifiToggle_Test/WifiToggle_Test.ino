//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki

#include "WEB.h"


void setup(){
  Serial.begin(115200);
}

void loop(){
  WiFiSetup();
  delay(5000);
  WiFiEnd();
  delay(5000);
}
