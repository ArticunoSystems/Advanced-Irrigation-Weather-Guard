int freezeTemp = 36; //Temperature to initiate purge
bool purgeState = false;
unsigned long CurPur_Time, LoopPur_Time;

int waterMain = ; //GPIO for Main Water Valve
int z1Valve = ; //GPIO for Zone 1 Valve
int z2Valve = ; //GPIO for Zone 2 Valve
int z3Valve = ; //GPIO for Zone 3 Valve
int airMain = ; //GPIO for Air Compressor Valve
int airPower = ; //GPIO for Compressor Power Toggle

void PurgeSetup(){
  pinMode(waterMain,OUTPUT);
  pinMode(z1Valve,OUTPUT);
  pinMode(z2Valve,OUTPUT);
  pinMode(z3Valve,OUTPUT);
  pinMode(airMain,OUTPUT);
  pinMode(airPower,OUTPUT);
}

void Purge(){
  Serial.println("----PURGING SYSTEM----");
  CurPur_Time = millis();
  if(){
    digitalWrite(waterMain,LOW);//CLOSE ALL Water Valves
    digitalWrite(z1Valve,LOW);
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,LOW);
    digitalWrite(airPower,HIGH);//Turn ON Air Compressor
  }
  else if(){ //Initiate Zone 1 Purge
    digitalWrite(airMain,HIGH); //OPEN Air Main Valve
    digitalWrite(z1Valve,HIGH); //OPEN Zone 1 Valve
  }
  else if(){ //Initiate Charge
    Serial.println("Zone 1 Purged");
    digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
    digitalWrite(z1Valve,LOW);  //CLOSE Zone 1 Valve
  }
  else if(){ //Inititate Zone 2 Purge
    digitalWrite(airMain,HIGH); //OPEN Air Main Valve
    digitalWrite(z2Valve,HIGH); //OPEN Zone 2 Valve
  }
  else if(){ //Initiate Charge
    Serial.println("Zone 2 Purged");
    digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
    digitalWrite(z2Valve,LOW);  //CLOSE Zone 2 Valve
  }
  else if(){ //Initiate Zone 3 Purge
    digitalWrite(airMain,HIGH); //OPEN Air Main Valve
    digitalWrite(z3Valve,HIGH); //OPEN Zone 3 Valve
  }
  else if(){ //End Purge Sequence
    Serial.println("Zone 3 Purged");
    digitalWrite(airMain,LOW);  //CLOSE Air Main Valve
    digitalWrite(z3Valve,LOW);  //CLOSE Zone 3 Valve
    digitalWrite(airPower,LOW); //Turn OFF Air Compressor
    Serial.println("----Purge Completed----");
  }
  else{
    
  }
}
void PurgeCheck(){
  if(fTemp1 < freezeTemp && fTemp2 < freezeTemp && fTemp3 < freezeTemp){
    Serial.println("Forecast meets freezing criteria for the next 3 hours")
    if(purgeState != true){
      purge();
    }
  }
  else if(){
    Serial.println("Ground Temp meets freezing criteria")
    if(purgeState != true){
      purge();
    }
  }
}
