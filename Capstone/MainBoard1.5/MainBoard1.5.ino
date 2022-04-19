//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki
//painlessMesh Wiki: https://gitlab.com/painlessMesh/painlessMesh/-/wikis/home

#include "BUZZ.h" ////no PreReq includes
#include "SENSE.h" //no PreReq includes
#include "LEAK.h" //SENSE.h is a prereq
#include "ONECALL.h" //no PreReq includes
#include "LCD.h" //no PreReq includes
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
  PurgeSetup();
  LCDsetup();
  BTTNSetup();
}

void loop(){
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
  if(WiFi.status() == WL_CONNECTED){
    OneCallLoop();
    WiFiEnd();
  }
  if(WiFi.status() != WL_CONNECTED){
    fTemp1 = 999;
    fTemp2 = 999;
    fTemp3 = 999;
    fTemp4 = 999;
  }
  Serial.println("---Returning to Mesh---");
  MeshSetup();
}
