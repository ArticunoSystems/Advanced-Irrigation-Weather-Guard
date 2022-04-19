unsigned long CurMen_Time, LoopMen_Time;
int MenLoop = 0;


void MenuSetup(){
  
}
void lvl0Default(){
  if(MenLoop = 0){
    LoopMen_Time = millis();
  }
  CurMen_Time = millis();
  if ((CurMen_Time >= LoopMen_Time) && (CurMen_Time <= (LoopMen_Time + 2000))&&(MenLoop != 1)){
    MenLoop = 1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("System is ");
    lcd.setCursor(2,1);
    if(purgeState == 0){
      lcd.print("NOT Purged");
    }
    if(purgeState == 1){
      lcd.print("PURGING");
    }
    if(purgeState == 2){
      lcd.print("PURGED");
    }
  }
  else if ((CurMen_Time > (LoopMen_Time+2000)) && (CurMen_Time <= (LoopMen_Time+4000))&&(MenLoop != 2)){
    MenLoop = 2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Zones Clogged:");
    lcd.setCursor(2,1);
    if((z1Clog == false)&&(z2Clog == false)&&(z2Clog == false)){
      lcd.print("NONE");
    }
    if(z1Clog == true){
      lcd.print("1,");
    }
    if(z2Clog == true){
      lcd.print("2,");
    }
    if(z3Clog == true){
      lcd.print("3,");
    }
  }
  else if ((CurMen_Time > (LoopMen_Time+4000)) && (CurMen_Time <= (LoopMen_Time+6000))&&(MenLoop != 3)){
    MenLoop = 3;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Zones Leaking:");
    lcd.setCursor(2,1);
    if((z1Leak == false)&&(z2Leak == false)&&(z2Leak == false)){
      lcd.print("NONE");
    }
    if(z1Leak == true){
      lcd.print("1,");
    }
    if(z2Leak == true){
      lcd.print("2,");
    }
    if(z3Leak == true){
      lcd.print("3,");
    }
  }
  else if(CurMen_Time > (LoopMen_Time+6000)){
    LoopMen_Time = millis();
  }
  
}

//--------Level 3--------
void lvl3Zone(){
  switch (lvl2){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("Z1:");
      //lcd.print(z1Flow);
      lcd.print("gal/min");
      lcd.setCursor(3,1);
      //lcd.print(z1Temp);
      lcd.print(" F");
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Z2:");
      //lcd.print(z2Flow);
      lcd.print("gal/min");
      lcd.setCursor(3,1);
      //lcd.print(z2Temp);
      lcd.print(" F");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Z3:");
      //lcd.print(z3Flow);
      lcd.print("gal/min");
      lcd.setCursor(3,1);
      //lcd.print(z3Temp);
      lcd.print(" F");
      break;
  }
}
void lvl3Man(){
  switch (lvl2){
    case 0: //Manual Purge
      lcd.setCursor(0,0);
      lcd.print("Starting Manual");
      lcd.setCursor(0,1);
      lcd.print("Purge");
      Purge();
      break;
    case 1: //Manual Water
      lcd.setCursor(0,0);
      lcd.print("Starting Manual");
      lcd.setCursor(0,1);
      lcd.print("Water");
      waterManual();
      break;
    case 2: //Manual Water
      lcd.setCursor(0,0);
      lcd.print("Starting Manual");
      lcd.setCursor(0,1);
      lcd.print("Water");
      waterManual();
      break;
  }
}
void lvl3Cal(){
  switch (lvl2){
    case 0: //Calibrate
      lcd.setCursor(0,0);
      lcd.print("Beginning");
      lcd.setCursor(0,1);
      lcd.print("Calibration");
      waterManual();
      //calFlow();
      break;
    case 1: //Calibrate
      lcd.setCursor(0,0);
      lcd.print("Beginning");
      lcd.setCursor(0,1);
      lcd.print("Calibration");
      //calFlow();
      break;
    case 2: //Calibrate
      lcd.setCursor(0,0);
      lcd.print("Beginning");
      lcd.setCursor(0,1);
      lcd.print("Calibration");
      //calFlow();
      break;
  }
}
void lvl3Water(){
  switch(lvl2){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("Set to 0/Week");
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Set to 1/Week");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Set to 2/Week");
      break;
    case 3:
      lcd.setCursor(0,0);
      lcd.print("Set to 3/Week");
      break;
    case 4:
      lcd.setCursor(0,0);
      lcd.print("Set to 4/Week");
      break;
    case 5:
      lcd.setCursor(0,0);
      lcd.print("Set to 5/Week");
      break;
  }
}
void lvl3Bzz(){
  switch(lvl2){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("Buzzer: ");
      lcd.setCursor(2,1);
      lcd.print("UNMUTED");
      BZZmute = false;
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Buzzer: ");
      lcd.setCursor(2,1);
      lcd.print("MUTED");
      BZZmute = true;
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Buzzer: ");
      lcd.setCursor(2,1);
      lcd.print("TESTING");
      digitalWrite(BZZpin, HIGH);
      break;
  }
}
void lvl3Menu(){
  switch (lvl1){
    case 0: //Zone Info
      lvl3Zone();
      break;
    case 1: //Manual
      lvl3Man();
      break;
    case 2: //Calibration
      lvl3Cal();
      break;
    case 3: //Water/Week
      lvl3Water();
      break;
    case 4: //Buzzer
      lvl3Bzz();
      break;
  }
}
//--------Level 2--------
void lvl2Zone(){
  switch (lvl2){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("Zone Info:");
      lcd.setCursor(2,1);
      lcd.print("Zone 1");
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Zone Info:");
      lcd.setCursor(2,1);
      lcd.print("Zone 2");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Zone Info:");
      lcd.setCursor(2,1);
      lcd.print("Zone 3");
      break;
  }
}
void lvl2Man(){
  switch (lvl2){
    case 0: //Manual Purge
      lcd.setCursor(0,0);
      lcd.print("Manual Control:");
      lcd.setCursor(2,1);
      lcd.print("Force Purge");
      break;
    case 1: //Manual Water
      lcd.setCursor(0,0);
      lcd.print("Manual Control:");
      lcd.setCursor(2,1);
      lcd.print("Force Water");
      break;
    case 2: //Manual Water
      lcd.setCursor(0,0);
      lcd.print("Manual Control:");
      lcd.setCursor(2,1);
      lcd.print("Force Water");
      break;
  }
}
void lvl2Cal(){
  switch (lvl2){
    case 0: //Calibrate
      lcd.setCursor(0,0);
      lcd.print("Calibration:");
      lcd.setCursor(2,1);
      lcd.print("Calibrate Flow");
      break;
    case 1: //Calibrate
      lcd.setCursor(0,0);
      lcd.print("Calibration:");
      lcd.setCursor(2,1);
      lcd.print("Calibrate Flow");
      break;
    case 2: //Calibrate
      lcd.setCursor(0,0);
      lcd.print("Calibration:");
      lcd.setCursor(2,1);
      lcd.print("Calibrate Flow");
      break;
  }
}
void lvl2Water(){
  switch(lvl2){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("Waters/Week:");
      lcd.setCursor(2,1);
      lcd.print("0");
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Waters/Week:");
      lcd.setCursor(2,1);
      lcd.print("1");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Waters/Week:");
      lcd.setCursor(2,1);
      lcd.print("2");
      break;
    case 3:
      lcd.setCursor(0,0);
      lcd.print("Waters/Week:");
      lcd.setCursor(2,1);
      lcd.print("3");
      break;
    case 4:
      lcd.setCursor(0,0);
      lcd.print("Waters/Week:");
      lcd.setCursor(2,1);
      lcd.print("4");
      break;
    case 5:
      lcd.setCursor(0,0);
      lcd.print("Waters/Week:");
      lcd.setCursor(2,1);
      lcd.print("5");
      break;
  }
}
void lvl2Bzz(){
  switch(lvl2){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("Turn Buzzer On");
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Turn Buzzer Off");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Test Buzzer");
      digitalWrite(BZZpin, LOW);
      break;
  }
}
void lvl2Menu(){
  switch (lvl1){
    case 0: //Zone Info
      lvl2Zone();
      break;
    case 1: //Manual
      lvl2Man();
      break;
    case 2: //Calibration
      lvl2Cal();
      break;
    case 3: //Water/Week
      lvl2Water();
      break;
    case 4: //Buzzer
      lvl2Bzz();
      break;
  }
}
//--------Level 1--------
void lvl1Menu(){
  switch (lvl1){
    case 0: //Zone info
      lcd.setCursor(0,0);
      lcd.print("Zone Info");
      break;
    case 1: //Manual
      lcd.setCursor(0,0);
      lcd.print("Manual Control");
      break;
    case 2: //Calibration
      lcd.setCursor(0,0);
      lcd.print("Calibration");
      break;
    case 3: //Water/Week
      lcd.setCursor(0,0);
      lcd.print("Waters/Week");
      break;
    case 4: //Buzzer
      lcd.setCursor(0,0);
      lcd.print("Buzzer Settings");
      break;
  }
}
//--------Core Loop--------
void MenuLoop(){
  IdleBttn();
  switch (curlvl){
    case 0: //default
      lvl0Default();
      break;
    case 1: //control options
      lvl1Menu();
      break;
    case 2: //user options
      lvl2Menu();
      break;
    case 3: //system action
      lvl3Menu();
      break;
  }
}
