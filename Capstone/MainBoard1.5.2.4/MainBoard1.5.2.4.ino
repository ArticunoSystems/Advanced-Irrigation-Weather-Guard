//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki
//painlessMesh Wiki: https://gitlab.com/painlessMesh/painlessMesh/-/wikis/home
boolean lcdUpToDate = false;
unsigned long fcast_Time;
unsigned long CurMain_Time,LoopMain_Time;

#include "LCD.h" //no PreReq includes
#include "BUZZ.h" ////no PreReq includes
#include "ONECALL.h" //no PreReq includes
#include "SENSE.h" //ONECALL.h
#include "LEAK.h" //SENSE.h is a prereq
#include "WEB.h" //no PreReq includes
#include "MESH.h" //SENSE.h is a PreReq include
#include "PURGE.h" //SENSE.h, MESH.h, BUZZ.h & ONECALL.h are PreReq includes
#include "WATER.h" //SENSE.h, LEAK.h, ONECALL.h, PURGE.h are prereqs
#include "BTTN.h"
#include "MENU.h"

bool WiFiCheck = false;

void WiFiTog(); //Specifaly so TaskScheduler doesn't give an error
Task Int(TASK_MINUTE*10, TASK_FOREVER, &WiFiTog);
  
void setup(){
  Serial.begin(115200);
  MeshSetup();
  userScheduler.addTask(Int);
  Int.enable();
  BuzzSetup();
  PurgeSetup();
  BTTNSetup();
  LCDsetup();
  lcd.setCursor(0,0);
  lcd.print("Articuno Systems");
}

void loop(){
  CurMain_Time = millis();
  MeshLoop();
  //if ((CurMain_Time - LoopMain_Time) % 100 == 0) {
    //LoopMain_Time = CurMain_Time;
    BTTNLoop();
    MenuLoop();
    PurgeCheck();
    WaterCheck();
  //}
}

void WiFiTog(){
  WiFiCheck = true;
  Serial.println("---Leaving Mesh---");
  mesh.stop();
  delay(100);
  WiFiSetup();
  lcd.clear();
  if(WiFi.status() == WL_CONNECTED){
    lcd.setCursor(0,0);
    lcd.print("Connected to:");
    lcd.setCursor(2,1);
    lcd.print(WiFi.localIP());
    OneCallLoop();
    fcast_Time = millis();
    WiFiEnd();
  }
  else if(WiFi.status() != WL_CONNECTED){
    lcd.setCursor(0,0);
    lcd.print("No Wifi");
    fTemp1 = 999;
    fTemp2 = 999;
    fTemp3 = 999;
    fTemp4 = 999;
  }
  Serial.println("---Returning to Mesh---");
  MeshSetup();
  WiFiCheck = false;
}
