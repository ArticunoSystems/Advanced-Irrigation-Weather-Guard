int WaterInterval = ;

void WaterSetup(){
  
}

void Sprinkle(){
  Serial.println("----PURGING SYSTEM----");
  
  CurPur_Time = millis();
  if(){
    digitalWrite(waterMain,LOW);//CLOSE ALL Water Valves
    digitalWrite(z1Valve,LOW);
    digitalWrite(z2Valve,LOW);
    digitalWrite(z3Valve,LOW);
  }
  else if(){ //Initiate Zone 1 Watering
    digitalWrite(z1Valve,HIGH); //OPEN Zone 1 Valve
    //z1Flow
  }
  else if(){ //Initiate Charge
    Serial.println("Zone 1 Purged");
    digitalWrite(z1Valve,LOW);  //CLOSE Zone 1 Valve
  }
  else if(){ //Inititate Zone 2 Purge
    digitalWrite(z2Valve,HIGH); //OPEN Zone 2 Valve
  }
  else if(){ //Initiate Charge
    Serial.println("Zone 2 Watered");
    digitalWrite(z2Valve,LOW);  //CLOSE Zone 2 Valve
  }
  else if(){ //Initiate Zone 3 Purge
    digitalWrite(z3Valve,HIGH); //OPEN Zone 3 Valve
  }
  else if(){ //End Purge Sequence
    Serial.println("Zone 3 Watered");
    digitalWrite(z3Valve,LOW);  //CLOSE Zone 3 Valve
    Serial.println("----WATERING COMPLETED----");
  }
  else{
    
  }
}
}
