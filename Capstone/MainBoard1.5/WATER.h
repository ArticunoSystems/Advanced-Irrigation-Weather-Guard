unsigned long CurWat_Time, LoopWat_Time; //Used for timing conditions
int WTmp = 0; //for debugging using serial monitor

//int airPower = 12; //GPIO for Compressor Power Toggle, Relay1
//int airMain = 15; //GPIO for Air Compressor Valve, Relay2
//int waterMain = 4; //GPIO for Main Water Valve, Relay3
//int z1Valve = 16; //GPIO for Zone 1 Valve, Relay4
//int z2Valve = 17; //GPIO for Zone 2 Valve, Relay5
//int z3Valve = 18; //GPIO for Zone 3 Valve, Relay6

int waterInt = 1000*30; //Minimum amount of time to wait between waterings
int waterLimit = 1; //rain in inches to prevent watering
int lastWater = 0; //millis time of last water sequence
bool waterState = false; //If the system is currently being watered

int wMillisDif = 0;

void WaterSetup(){
  pinMode(waterMain,OUTPUT);
  pinMode(z1Valve,OUTPUT);
  pinMode(z2Valve,OUTPUT);
  pinMode(z3Valve,OUTPUT);
  pinMode(airMain,OUTPUT);
  pinMode(airPower,OUTPUT);
}

void Sprinkle(){
  if(waterState != true){
    Serial.println("----WATERING SYSTEM----");
    waterState = true; //signifies system is watering
    purgeState = 0; //Update state of purge
    LoopWat_Time = millis();
  }
  CurWat_Time = millis();
  if((CurWat_Time >= LoopWat_Time) && (CurWat_Time <= (LoopWat_Time + 3000))){ //Water Zone 1
    if(WTmp == 1){
      Serial.println("Watering Zone 1");
      WTmp++;
    }
    digitalWrite(waterMain,HIGH);//OPEN Water Main
    digitalWrite(z1Valve,HIGH);
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,LOW);
    digitalWrite(airPower,LOW);//Turn OFF Air Compressor
    z1Check();
  }
  else if((CurWat_Time > (LoopWat_Time+3000)) && (CurWat_Time <= (LoopWat_Time+6000))){ //Water Zone 2
    if(WTmp == 2){
      Serial.println("Watering Zone 2");
      WTmp++;
    }
    digitalWrite(z1Valve,LOW);
    digitalWrite(z2Valve,HIGH);
    z2Check();
  }
  else if((CurWat_Time > (LoopWat_Time+6000)) && (CurWat_Time <= (LoopWat_Time+9000))){ //Water Zone 3
    if(WTmp == 3){
      Serial.println("Watering Zone 3");
      WTmp++;
    }
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,HIGH);
    z3Check();
  }
  else if((CurWat_Time > (LoopWat_Time+9000)) && (CurWat_Time <= (LoopWat_Time+12000))){ //End Watering
    digitalWrite(z3Valve,LOW);
    digitalWrite(waterMain,LOW);
    Serial.println("----WATERING COMPLETED----");
    WTmp = 0;
    waterState = false; //signifies system is NOT watering
    lastWater = millis();
  }
  else{
    Serial.println("Water Timing Error");
  }
}

void waterManual(){
  if((waterState == false)&&(purgeState != 1)){
    Sprinkle();
  }
}
void WaterCheck(){
  CurWat_Time = millis();
  if((waterState == true)&&(purgeState != 1)){
    Sprinkle();
  }
  if(CurWat_Time >= lastWater){
    wMillisDif = CurWat_Time - lastWater;
  }
  if(CurWat_Time < lastWater){
    wMillisDif = (4294967295 - lastWater) + CurWat_Time;
  }
  if((wMillisDif > waterInt)&&(purgeState !=1)){ //Time since last water comparison
    if(waterState == false){
      Serial.println("enough time has passed since last water");
      if((fRain0 < waterLimit) || (fRain1 < waterLimit)){ //Rain Forecast check
        if(WTmp == 0){
          Serial.println("Forecast meets watering criteria for the day");
          WTmp++;
        }
        Sprinkle();
      }
    }
  }
}
