//Articuno Systems
//Project Manager: Bradley Hartman
//Hardware Engineer: Dylan Hromcik
//Integration Engineer: Nathan Armstrong
//Software Engineer: Hyun Ki David Lee
//---------------
//Made by Hyun Ki David Lee
//TaskScheduler Wiki: https://github.com/arkhipenko/TaskScheduler/wiki
//painlessMesh Wiki: https://gitlab.com/painlessMesh/painlessMesh/-/wikis/home
//

#include "MESH.h"
#include "WEB.h"
#include "FORECAST.h"

//Scheduler userScheduler;
//void MeshTog();
//Task Tog(TASK_MINUTE*1, TASK_FOREVER, &MeshTog);
void WiFiTog(){
  WiFiSetup();
  ForecastLoop();
  WiFiEnd();
}

Task Int(TASK_MINUTE, TASK_FOREVER, &WiFiTog);
  
void setup(){
  Serial.begin(115200);
  MeshSetup();
  //userScheduler.addTask(Tog);
  //Tog.enable();
  userScheduler.addTask(Int);
  Int.enable();
}

void loop(){
  MeshLoop();
}

void MeshTog(){
  Serial.println("!!!---Seperating from Mesh---!!!");
  mesh.stop();
  delay(1000);
  Serial.println("!!!---Reconnecting to Mesh---!!!");
  MeshSetup();
}
