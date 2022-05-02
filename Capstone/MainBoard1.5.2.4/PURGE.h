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

void PurgeSetup(){
  pinMode(waterMain,OUTPUT);
  pinMode(z1Valve,OUTPUT);
  pinMode(z2Valve,OUTPUT);
  pinMode(z3Valve,OUTPUT);
  pinMode(airMain,OUTPUT);
  pinMode(airPower,OUTPUT);

  digitalWrite(waterMain,LOW);
  digitalWrite(z1Valve,LOW);
  digitalWrite(z2Valve,LOW);
  digitalWrite(z3Valve,LOW);
  digitalWrite(airMain,LOW);
  digitalWrite(airPower,LOW);
}

void Purge(){
  BuzzLoop();
  if(purgeState != 1){
    Serial.println("----PURGING SYSTEM----");
    purgeState = 1;
    LoopPur_Time = millis();
  }
  CurPur_Time = millis();
  if ((CurPur_Time - LoopPur_Time) % 50 == 0) { //only update lvl0 every 50ms
    if((CurPur_Time >= LoopPur_Time) && (CurPur_Time <= ((ChargeTime*2)+(PurgeTime*0)+LoopPur_Time))){ //Initiate Charge
      digitalWrite(airMain,LOW);
      digitalWrite(waterMain,LOW);//CLOSE ALL Water Valves
      digitalWrite(z1Valve,LOW);
      digitalWrite(z2Valve,LOW);
      digitalWrite(z3Valve,LOW);
      digitalWrite(airPower,HIGH);//Turn ON Air Compressor
      BuzzLoop();
    }
    if((CurPur_Time > ((ChargeTime*2)+(PurgeTime*0)+LoopPur_Time)) && (CurPur_Time <= ((ChargeTime*2)+(PurgeTime*1)+LoopPur_Time))){ //Initiate Zone 1 Purge
      digitalWrite(airMain,HIGH); //OPEN Air Main Valve
      digitalWrite(z1Valve,HIGH); //OPEN Zone 1 Valve
    }
    if((CurPur_Time > ((ChargeTime*2)+(PurgeTime*1)+LoopPur_Time)) && (CurPur_Time <= ((ChargeTime*3)+(PurgeTime*1)+LoopPur_Time))){ //Initiate Charge
      if(PTmp == 1){
        Serial.println("Zone 1 Purged");
        PTmp++;
      }
      digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
      digitalWrite(z1Valve,LOW);  //CLOSE Zone 1 Valve
    }
    if((CurPur_Time > ((ChargeTime*3)+(PurgeTime*1)+LoopPur_Time)) && (CurPur_Time <= ((ChargeTime*3)+(PurgeTime*2)+LoopPur_Time))){ //Inititate Zone 2 Purge
      digitalWrite(airMain,HIGH); //OPEN Air Main Valve
      digitalWrite(z2Valve,HIGH); //OPEN Zone 2 Valve
    }
    if((CurPur_Time > ((ChargeTime*3)+(PurgeTime*2)+LoopPur_Time)) && (CurPur_Time <= ((ChargeTime*4)+(PurgeTime*2)+LoopPur_Time))){ //Initiate Charge
      if(PTmp == 2){
        Serial.println("Zone 2 Purged");
        PTmp++;
      }
      digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
      digitalWrite(z2Valve,LOW);  //CLOSE Zone 2 Valve
    }
    if((CurPur_Time > ((ChargeTime*4)+(PurgeTime*2)+LoopPur_Time)) && (CurPur_Time <= ((ChargeTime*4)+(PurgeTime*3)+LoopPur_Time))){ //Initiate Zone 3 Purge
      digitalWrite(airMain,HIGH); //OPEN Air Main Valve
      digitalWrite(z3Valve,HIGH); //OPEN Zone 3 Valve
      BuzzLoop();
    }
    if(CurPur_Time > ((ChargeTime*4)+(PurgeTime*3)+LoopPur_Time)){ //&& (CurPur_Time <= ((ChargeTime*5)+(PurgeTime*3)+LoopPur_Time))){ //delay before exit
      if(PTmp == 3){
        Serial.println("Zone 3 Purged");
        PTmp++;
      }
      digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
      digitalWrite(z3Valve,LOW);  //CLOSE Zone 3 Valve
      digitalWrite(airPower,LOW); //Turn OFF Air Compressor
      digitalWrite(BZZpin, LOW);
      purgeState = 2;
      PTmp=0;
      Serial.println("----PURGE COMPLETED----");
    }
//    if(CurPur_Time > ((ChargeTime*4)+(PurgeTime*3)+LoopPur_Time)){ //End Purge Sequence
//      digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
//      digitalWrite(z3Valve,LOW);  //CLOSE Zone 3 Valve
//      digitalWrite(airPower,LOW); //Turn OFF Air Compressor
//      digitalWrite(BZZpin, LOW);
      
//    }
    else{
      Serial.println("Purge Timing Error");
    }
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
