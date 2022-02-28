#include <TaskScheduler.h>

Task taskPurge
void Purge(){
  Serial.write("Conducting Freeze Purge. \n") //Serial message
  digitalWrite(##, HIGH): //Turn ON Purge Status LED
  digitalWrite(##, LOW): //Close Main Valve
  digitalWrite(##, LOW): //Close Valve 1
  digitalWrite(##, LOW): //Close Valve 2
  digitalWrite(##, LOW): //Close Valve 3
  digitalWrite(##, HIGH): //Turn ON Compressor Relay
  
  Serial.write("Purging Zone 1. \n") //Serial message
  digitalWrite(##, HIGH): //Open Valve 1
  delay(#00000) //Run air cycle for # amount of time
  digitalWrite(##, LOW): //Close Valve 1
  
  Serial.write("Purging Zone 2. \n") //Serial message
  digitalWrite(##, HIGH): //Open Valve 2
  delay(#00000) //Run air cycle for # amount of time
  digitalWrite(##, LOW): //Close Valve 2
  
  Serial.write("Purging Zone 3. \n") //Serial message
  digitalWrite(##, HIGH): //Open Valve 3
  delay(#00000) //Run air cycle for # amount of time
  digitalWrite(##, LOW): //Close Valve 3
  
  digitalWrite(##, LOW): //Turn OFF Compressor Relay
