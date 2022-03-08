#include <TaskScheduler.h>

int WMain = 1;
int WZone1 = 2;
int WZone2 = 3;
int WZone3 = 4;

void Water(){
  Serial.write("Conducting Watering. \n"); //Serial message
  digitalWrite(WMain, HIGH); //Open Main Valve
  
  Serial.write("Watering Zone 1. \n"); //Serial message
  digitalWrite(WZone1, HIGH); //Open Valve 1
  //delay(#00000) //Run water cycle for # amount of time
  //flow1=***//Update flow 1 data
  digitalWrite(WZone1, LOW); //Close Valve 1
  
  Serial.write("Watering Zone 2. \n"); //Serial message
  digitalWrite(WZone2, HIGH); //Open Valve 2
  //delay(#000000) //Run water cycle for # amount of time
  //flow2=***//Update flow 2 data
  digitalWrite(WZone2, LOW); //Close Valve 2
  
  Serial.write("Watering Zone 3. \n"); //Serial message
  digitalWrite(WZone3, HIGH); //Open Valve 3
  //delay(#00000) //Run water cycle for # amount of time
  //flow3=***//Update flow 3 data
  digitalWrite(WZone3, LOW); //Close Valve 3

  digitalWrite(WMain, LOW); //Close Main Valve
  Serial.write("Finished with Watering. \n"); //Serial message
}
