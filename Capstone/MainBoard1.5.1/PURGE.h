int freezeTemp = 36; //Temperature to initiate purge
int purgeState = 0; //0=Not Purged, 1=Purging, 2=Purged
unsigned long CurPur_Time, LoopPur_Time; //Used for timing conditions
//int PurgeLength = 3000;//how long to purge a specific zone
//int ChargeLength = 1000;//how long to allow the compressor to charge
int PTmp = 0; //for debugging using serial monitor

int airPower = 12; //GPIO for Compressor Power Toggle, Relay1
int airMain = 15; //GPIO for Air Compressor Valve, Relay2
int waterMain = 4; //GPIO for Main Water Valve, Relay3
int z1Valve = 16; //GPIO for Zone 1 Valve, Relay4
int z2Valve = 17; //GPIO for Zone 2 Valve, Relay5
int z3Valve = 18; //GPIO for Zone 3 Valve, Relay6

void PurgeSetup(){
  pinMode(waterMain,OUTPUT);
  pinMode(z1Valve,OUTPUT);
  pinMode(z2Valve,OUTPUT);
  pinMode(z3Valve,OUTPUT);
  pinMode(airMain,OUTPUT);
  pinMode(airPower,OUTPUT);
}

void Purge(){
  BuzzLoop();
  if(purgeState != 1){
    Serial.println("----PURGING SYSTEM----");
    purgeState = 1;
    LoopPur_Time = millis();
  }
  CurPur_Time = millis();
  if((CurPur_Time >= LoopPur_Time) && (CurPur_Time <= (LoopPur_Time + 1000))){ //Initiate Charge
    digitalWrite(waterMain,LOW);//CLOSE ALL Water Valves
    digitalWrite(z1Valve,LOW);
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,LOW);
    digitalWrite(airPower,HIGH);//Turn ON Air Compressor
  }
  else if((CurPur_Time > (LoopPur_Time+1000)) && (CurPur_Time <= (LoopPur_Time+4000))){ //Initiate Zone 1 Purge
    digitalWrite(airMain,HIGH); //OPEN Air Main Valve
    digitalWrite(z1Valve,HIGH); //OPEN Zone 1 Valve
  }
  else if((CurPur_Time > (LoopPur_Time+4000)) && (CurPur_Time <= (LoopPur_Time+5000))){ //Initiate Charge
    if(PTmp == 1){
      Serial.println("Zone 1 Purged");
      PTmp++;
    }
    digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
    digitalWrite(z1Valve,LOW);  //CLOSE Zone 1 Valve
  }
  else if((CurPur_Time > (LoopPur_Time+5000)) && (CurPur_Time <= (LoopPur_Time+8000))){ //Inititate Zone 2 Purge
    digitalWrite(airMain,HIGH); //OPEN Air Main Valve
    digitalWrite(z2Valve,HIGH); //OPEN Zone 2 Valve
  }
  else if((CurPur_Time > (LoopPur_Time+8000)) && (CurPur_Time <= (LoopPur_Time+9000))){ //Initiate Charge
    if(PTmp == 2){
      Serial.println("Zone 2 Purged");
      PTmp++;
    }
    digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
    digitalWrite(z2Valve,LOW);  //CLOSE Zone 2 Valve
  }
  else if((CurPur_Time > (LoopPur_Time+9000)) && (CurPur_Time <= (LoopPur_Time+12000))){ //Initiate Zone 3 Purge
    digitalWrite(airMain,HIGH); //OPEN Air Main Valve
    digitalWrite(z3Valve,HIGH); //OPEN Zone 3 Valve
  }
  else if((CurPur_Time > (LoopPur_Time+12000)) && (CurPur_Time <= (LoopPur_Time+13000))){ //End Purge Sequence
    if(PTmp == 3){
      Serial.println("Zone 3 Purged");
      PTmp++;
    }
    digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
    digitalWrite(z3Valve,LOW);  //CLOSE Zone 3 Valve
    digitalWrite(airPower,LOW); //Turn OFF Air Compressor
    purgeState = 2;
    PTmp=0;
    Serial.println("----PURGE COMPLETED----");
  }
  else{
    Serial.println("Purge Timing Error");
  }
}
void PurgeCheck(){
  if(purgeState == 1){
    Purge();
  }
  if((fTemp1 < freezeTemp) || (fTemp2 < freezeTemp) || (fTemp3 < freezeTemp)){
    if(purgeState != 2){
      if(PTmp == 0){
        Serial.println("Forecast meets freezing criteria for the next 3 hours");
        PTmp++;
      }
      Purge();
    }
  }
  else if((z1Temp < freezeTemp) || (z2Temp < freezeTemp) || (z3Temp < freezeTemp)){
    if(purgeState != 2){
      if(PTmp == 0){
        Serial.println("Ground Temp meets freezing criteria");
        PTmp++;
      }
      Purge();
    }
  }
}
