//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki
//painlessMesh Wiki: https://gitlab.com/painlessMesh/painlessMesh/-/wikis/home

#include "LCD.h" //no PreReq includes
#include "BUZZ.h" ////no PreReq includes
#include "SENSE.h" //no PreReq includes
#include "LEAK.h" //SENSE.h is a prereq
#include "ONECALL.h" //no PreReq includes
#include "WEB.h" //no PreReq includes
#include "MESH.h" //SENSE.h is a PreReq include
#include "PURGE.h" //SENSE.h, MESH.h, BUZZ.h & ONECALL.h are PreReq includes
#include "WATER.h" //SENSE.h, LEAK.h, ONECALL.h, PURGE.h are prereqs
#include "BTTN.h"
#include "MENU.h"


void WiFiTog(); //Specifaly so TaskScheduler doesn't give an error
Task Int(TASK_MINUTE*10, TASK_FOREVER, &WiFiTog);
  
void setup(){
  Serial.begin(115200);
  MeshSetup();
  userScheduler.addTask(Int);
  Int.enable();
  BuzzSetup();
  PurgeSetup();
  LCDsetup();
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Articuno Systems");
  BTTNSetup();
}

void loop(){
  BTTNLoop();
  MenuLoop();
  if(purgeState !=1){
    MeshLoop();
  }
  if((purgeState ==2)&&(z1Temp>50)){ //temporary state reset
    purgeState=0;
  }
  PurgeCheck();
  if(purgeState != 1){
    WaterCheck();
  }
}

void WiFiTog(){
  Serial.println("---Leaving Mesh---");
  mesh.stop();
  WiFiSetup();
  lcd.clear();
  if(WiFi.status() == WL_CONNECTED){
    lcd.setCursor(0,0);
    lcd.print("Connected to:");
    lcd.setCursor(2,1);
    lcd.print(WiFi.localIP());
    OneCallLoop();
    WiFiEnd();
  }
  if(WiFi.status() != WL_CONNECTED){
    lcd.setCursor(0,0);
    lcd.print("No Wifi");
    fTemp1 = 999;
    fTemp2 = 999;
    fTemp3 = 999;
    fTemp4 = 999;
  }
  Serial.println("---Returning to Mesh---");
  MeshSetup();
}
