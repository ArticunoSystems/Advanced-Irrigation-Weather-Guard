#include <TaskScheduler.h>

void Water(){
  Serial.write("Conducting Watering. \n") //Serial message
  
  Serial.write("Watering Zone 1. \n") //Serial message
  digitalWrite(##, HIGH): //Open Valve 1
  delay(#00000) //Run water cycle for # amount of time
  flow1=***//Update flow 1 data
  digitalWrite(1, LOW): //Close Valve 1
  
  Serial.write("Watering Zone 2. \n") //Serial message
  digitalWrite(##, HIGH): //Open Valve 2
  delay(#000000) //Run water cycle for # amount of time
  flow2=***//Update flow 2 data
  digitalWrite(##, LOW): //Close Valve 2
  
  Serial.write("Watering Zone 3. \n") //Serial message
  digitalWrite(##, HIGH): //Open Valve 3
  delay(#00000) //Run water cycle for # amount of time
  flow3=***//Update flow 3 data
  digitalWrite(##, LOW): //Close Valve 3
  
  Serial.write("Finished with Watering. \n") //Serial message
  lastWater = #######: //update "time of last water" with current time
}
