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

//----PURGE Variables----
int freezeTemp = 55; //Temperature to initiate purge
int purgeState = 0; //0=Not Purged, 1=Purging, 2=Purged
unsigned long CurPur_Time, LoopPur_Time; //Used for timing conditions
int PurgeTime = 15000;//how long to purge a specific zone
int ChargeTime = 15000;//how long to allow the compressor to charge
int PTmp = 0; //for debugging using serial monitor

int airPower = 2; //GPIO for Compressor Power Toggle, Offboard Relay
int airMain = 23; //GPIO for Air Compressor Valve, Relay8
int waterMain = 16; //GPIO for Main Water Valve, Relay3
int z1Valve = 12; //GPIO for Zone 1 Valve, Relay1
int z2Valve = 15; //GPIO for Zone 2 Valve, Relay2
int z3Valve = 4; //GPIO for Zone 3 Valve, Relay3

//----WATER Variables----
unsigned long CurWat_Time, LoopWat_Time; //Used for timing conditions
int WTmp = 0; //for debugging using serial monitor

int SprinkleTime = 30000;//how long to purge a specific zone
int DelayTime = 2000;//how long to allow the compressor to charge

int waterInt = 1000*30; //Minimum amount of time to wait between waterings
int waterLimit = 1; //rain in inches to prevent watering
int lastWater = 0; //millis time of last water sequence
bool waterState = false; //If the system is currently being watered

int wMillisDif = 0;

#include "LCD.h" //no PreReq includes
#include "BUZZ.h" ////no PreReq includes
#include "ONECALL.h" //no PreReq includes
#include "SENSE.h" //ONECALL.h
#include "LEAK.h" //SENSE.h is a prereq
#include "MESH.h" //SENSE.h is a PreReq include
#include "MAIL.h"
#include "PURGE.h" //SENSE.h, MESH.h, BUZZ.h & ONECALL.h are PreReq includes
#include "WATER.h" //SENSE.h, LEAK.h, ONECALL.h, PURGE.h are prereqs
#include "WEB.h" //no PreReq includes
#include "BTTN.h"
#include "MENU.h"

bool WiFiCheck = false;

void WiFiTog(); //Specifaly so TaskScheduler doesn't give an error
Task Int(TASK_MINUTE*5, TASK_FOREVER, &WiFiTog);
  
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
  BTTNLoop();
  MenuLoop();
  PurgeCheck();
  WaterCheck();
}

void WiFiTog(){
  WiFiCheck = true;
  Serial.println("---Leaving Mesh---");
  mesh.stop();
  delay(200);
  WiFiSetup();
  lcd.clear();
  if(WiFi.status() == WL_CONNECTED){
    lcd.setCursor(0,0);
    lcd.print("Connected to:");
    lcd.setCursor(2,1);
    lcd.print(WiFi.localIP());
    OneCallLoop();
    sendFinal();
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
