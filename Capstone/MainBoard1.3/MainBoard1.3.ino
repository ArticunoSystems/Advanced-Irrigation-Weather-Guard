//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki
//painlessMesh Wiki: https://gitlab.com/painlessMesh/painlessMesh/-/wikis/home

//#include "BUZZ.h" ////no PreReq includes
#include "SENSE.h" //no PreReq includes
#include "ONECALL.h" //no PreReq includes
#include "MESH.h" //SENSE.h is a PreReq include
#include "PURGE.h" //SENSE.h, MESH.h, BUZZ.h & ONECALL.h are PreReq includes
#include "LCD.h" //SENSE.h, MESH.h, ONECALL.h, PURGE.h, WATER.h are PreReq includes
#include "WEB.h" //no PreReq includes


void WiFiTog(); //Specifaly so TaskScheduler doesn't give an error
Task Int(TASK_MINUTE*10, TASK_FOREVER, &WiFiTog);
  
void setup(){
  Serial.begin(115200);
  MeshSetup();
  userScheduler.addTask(Int);
  Int.enable();
}

void loop(){
  MeshLoop();
}

void WiFiTog(){
  Serial.println("---Leaving Mesh---");
  WiFiSetup();
  OneCallLoop();
  WiFiEnd();
  Serial.println("---Returning to Mesh---");
  MeshSetup();
}
