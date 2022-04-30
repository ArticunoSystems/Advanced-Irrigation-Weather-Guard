unsigned long CurWat_Time, LoopWat_Time; //Used for timing conditions
int WTmp = 0; //for debugging using serial monitor

//int airPower = 12; //GPIO for Compressor Power Toggle, Relay1
//int airMain = 15; //GPIO for Air Compressor Valve, Relay2
//int waterMain = 4; //GPIO for Main Water Valve, Relay3
//int z1Valve = 16; //GPIO for Zone 1 Valve, Relay4
//int z2Valve = 17; //GPIO for Zone 2 Valve, Relay5
//int z3Valve = 18; //GPIO for Zone 3 Valve, Relay6

int SprinkleTime = 30000;//how long to purge a specific zone
int DelayTime = 2000;//how long to allow the compressor to charge

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
  if(purgeState !=1){
    if(waterState != true){
      Serial.println("----WATERING SYSTEM----");
      waterState = true; //signifies system is watering
      purgeState = 0; //Update state of purge
      LoopWat_Time = millis();
    }
    CurWat_Time = millis();
    if((CurWat_Time >= LoopWat_Time) && (CurWat_Time <= ((DelayTime*0)+(SprinkleTime*1)+LoopWat_Time))){ //Water Zone 1
      if(WTmp == 1){
        Serial.println("Watering Zone 1");
        WTmp++;
      }
      digitalWrite(waterMain,HIGH);//OPEN Water Main
      digitalWrite(z1Valve,HIGH);
      digitalWrite(z2Valve,LOW);
      digitalWrite(z3Valve,LOW);
      digitalWrite(airMain,LOW);
      digitalWrite(airPower,LOW);//Turn OFF Air Compressor
      z1Check();
    }
    if((CurWat_Time > ((DelayTime*0)+(SprinkleTime*1)+LoopWat_Time)) && (CurWat_Time <= ((DelayTime*1)+(SprinkleTime*1)+LoopWat_Time))){
      digitalWrite(waterMain,LOW);//CLOSE Water Main
      digitalWrite(z1Valve,LOW);
      digitalWrite(z2Valve,LOW);
      digitalWrite(z3Valve,LOW);
      digitalWrite(airMain,LOW);
      digitalWrite(airPower,LOW);//Turn OFF Air Compressor
    }
    if((CurWat_Time > ((DelayTime*1)+(SprinkleTime*1)+LoopWat_Time)) && (CurWat_Time <= ((DelayTime*1)+(SprinkleTime*2)+LoopWat_Time))){ //Water Zone 2
      if(WTmp == 2){
        Serial.println("Watering Zone 2");
        WTmp++;
      }
      digitalWrite(waterMain,HIGH);//OPEN Water Main
      digitalWrite(z1Valve,LOW);
      digitalWrite(z2Valve,HIGH);
      digitalWrite(z3Valve,LOW);
      digitalWrite(airMain,LOW);
      digitalWrite(airPower,LOW);//Turn OFF Air Compressor
      z2Check();
    }
    if((CurWat_Time > ((DelayTime*1)+(SprinkleTime*2)+LoopWat_Time)) && (CurWat_Time <= ((DelayTime*2)+(SprinkleTime*2)+LoopWat_Time))){
      digitalWrite(waterMain,LOW);//CLOSE Water Main
      digitalWrite(z1Valve,LOW);
      digitalWrite(z2Valve,LOW);
      digitalWrite(z3Valve,LOW);
      digitalWrite(airMain,LOW);
      digitalWrite(airPower,LOW);//Turn OFF Air Compressor
    }
    if((CurWat_Time > ((DelayTime*2)+(SprinkleTime*2)+LoopWat_Time)) && (CurWat_Time <= ((DelayTime*2)+(SprinkleTime*3)+LoopWat_Time))){ //Water Zone 3
      if(WTmp == 3){
        Serial.println("Watering Zone 3");
        WTmp++;
      }
      digitalWrite(waterMain,HIGH);//OPEN Water Main
      digitalWrite(z1Valve,LOW);
      digitalWrite(z2Valve,LOW);
      digitalWrite(z3Valve,HIGH);
      digitalWrite(airMain,LOW);
      digitalWrite(airPower,LOW);//Turn OFF Air Compressor
      z3Check();
    }
    if((CurWat_Time > ((DelayTime*2)+(SprinkleTime*3)+LoopWat_Time))){ //End Watering
      digitalWrite(waterMain,LOW);//CLOSE Water Main
      digitalWrite(z1Valve,LOW);
      digitalWrite(z2Valve,LOW);
      digitalWrite(z3Valve,LOW);
      digitalWrite(airMain,LOW);
      digitalWrite(airPower,LOW);//Turn OFF Air Compressor
      Serial.println("----WATERING COMPLETED----");
      WTmp = 0;
      waterState = false; //signifies system is NOT watering
      lastWater = millis();
      if(CalFlow == true){
        int nodes = 0;
        int total = 0;
        if(Calz1Flow != 0){
          total += Calz1Flow;
          nodes +=1;
        }
        if(Calz2Flow != 0){
          total += Calz2Flow;
          nodes +=1;
        }
        if(Calz3Flow != 0){
          total += Calz3Flow;
          nodes +=1;
        }
        tarFlow = total/nodes;
        Serial.println("Target Flow Rate Calibrated");
        CalFlow = false;
      }
    }
  }
}

void waterManual(){
  if((waterState == false)&&(purgeState != 1)){
    Sprinkle();
  }
}
void WaterCheck(){
  CurWat_Time = millis();
  if(purgeState == 1){
    waterState = false;
    WTmp = 0;
  }
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
      Serial.println(fRain0);
      Serial.println(fRain1);
      if((fRain0 < waterLimit) || (fRain1 < waterLimit)){ //Rain Forecast check
        if((z1Temp < freezeTemp) || (z2Temp < freezeTemp) || (z3Temp < freezeTemp) || (fTemp1 < freezeTemp) || (fTemp2 < freezeTemp) || (fTemp3 < freezeTemp)){
          if(WTmp == 0){
            Serial.println("Forecast meets watering criteria for the day");
            WTmp++;
          }
          Sprinkle();
        }
      }
      else if(fRain0 > waterLimit){
        lastWater = millis();
      }
    }
  }
}
