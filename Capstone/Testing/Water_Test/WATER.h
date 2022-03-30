unsigned long CurWat_Time, LoopWat_Time; //Used for timing conditions
int WTmp = 0; //for debugging using serial monitor

int waterMain = 4; //GPIO for Main Water Valve
int z1Valve = 16; //GPIO for Zone 1 Valve
int z2Valve = 17; //GPIO for Zone 2 Valve
int z3Valve = 5; //GPIO for Zone 3 Valve
int airMain = 18; //GPIO for Air Compressor Valve
int airPower = 19; //GPIO for Compressor Power Toggle

void WaterSetup(){
  pinMode(waterMain,OUTPUT);
  pinMode(z1Valve,OUTPUT);
  pinMode(z2Valve,OUTPUT);
  pinMode(z3Valve,OUTPUT);
  pinMode(airMain,OUTPUT);
  pinMode(airPower,OUTPUT);
}

void Sprinkle(){
  if(purgeState != 1){
    Serial.println("----WATERING SYSTEM----");
    purgeState = 1;
    LoopWat_Time = millis();
  }
  CurWat_Time = millis();
  if((CurWat_Time >= LoopWat_Time) && (CurWat_Time <= (LoopWat_Time + 3000))){ //Water Zone 1
    digitalWrite(waterMain,HIGH);//OPEN Water Main
    digitalWrite(z1Valve,HIGH);
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,LOW);
    digitalWrite(airPower,LOW);//Turn OFF Air Compressor
  }
  else if((CurWat_Time > (LoopWat_Time+3000)) && (CurPur_Time <= (LoopPur_Time+6000))){ //Water Zone 2
    digitalWrite(z1Valve,LOW);
    digitalWrite(z2Valve,HIGH);
  }
  else if((CurWat_Time > (LoopWat_Time+6000)) && (CurPur_Time <= (LoopPur_Time+9000))){ //Water Zone 3
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,HIGH);
  }
  else{
    Serial.println("Water Timing Error");
  }
}
void WaterCheck(){
  if(WaterTime > ___){ //Time since last water comparison
    if(fRain1 < freezeTemp){ //Rain Forecast check
      if(WTmp == 0){
        Serial.println("Forecast meets watering criteria for the day");
        WTmp++;
      }
      Sprinkle();
    }
  }
}
