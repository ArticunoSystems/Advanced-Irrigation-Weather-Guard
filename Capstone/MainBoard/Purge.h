#include <TaskScheduler.h>

int PComp = 0;
int PMain = 1;
int PZone1 = 2;
int PZone2 = 3;
int PZone3 = 4;

Task taskPurge;
void Purge(){
  Serial.write("Conducting Freeze Purge. \n"); //Serial message
  digitalWrite(2, HIGH); //Turn ON Purge Status LED
  digitalWrite(PMain, LOW); //Close Main Valve
  digitalWrite(PZone1, LOW); //Close Valve 1
  digitalWrite(PZone2, LOW); //Close Valve 2
  digitalWrite(PZone3, LOW); //Close Valve 3
  digitalWrite(PComp, HIGH); //Turn ON Compressor Relay
  
  Serial.write("Purging Zone 1. \n"); //Serial message
  digitalWrite(PZone1, HIGH); //Open Valve 1
  delay(000000); //Run air cycle for # amount of time
  digitalWrite(PZone2, LOW); //Close Valve 1
  
  Serial.write("Purging Zone 2. \n"); //Serial message
  digitalWrite(PZone2, HIGH); //Open Valve 2
  delay(000000); //Run air cycle for # amount of time
  digitalWrite(PZone2, LOW); //Close Valve 2
  
  Serial.write("Purging Zone 3. \n"); //Serial message
  digitalWrite(PZone3, HIGH); //Open Valve 3
  delay(000000); //Run air cycle for # amount of time
  digitalWrite(PZone3, LOW); //Close Valve 3
  
  digitalWrite(PComp, LOW); //Turn OFF Compressor Relay
}
