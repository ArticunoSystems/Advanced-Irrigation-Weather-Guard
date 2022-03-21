//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki
//painlessMesh Wiki: https://gitlab.com/painlessMesh/painlessMesh/-/wikis/home

#include "MESH.h"
#include "WEB.h"

void WiFiTog();
Task Int(TASK_MINUTE, TASK_FOREVER, &WiFiTog);
  
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
  WiFiEnd();
  Serial.println("---Returning to Mesh---");
  MeshSetup();
}
