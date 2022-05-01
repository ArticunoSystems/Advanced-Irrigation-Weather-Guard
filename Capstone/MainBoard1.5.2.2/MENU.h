unsigned long CurMen_Time, LoopMen_Time;
int MenLoop = 0;

void MenuSetup() {

}
void lvl0Default() {
  if (MenLoop = 0) {
    LoopMen_Time = millis();
  }
  CurMen_Time = millis();
  if ((CurMen_Time >= LoopMen_Time) && (CurMen_Time <= (LoopMen_Time + 2000))) {
    lcd.setCursor(0, 0);
    lcd.print("System is");
    lcd.print("           ");
    lcd.setCursor(2, 1);
    if (purgeState == 0) {
      lcd.print("NOT Purged");
    }
    if (purgeState == 1) {
      lcd.print("PURGING");
    }
    if (purgeState == 2) {
      lcd.print("PURGED");
    }
    lcd.print("           ");
  }
  if ((CurMen_Time > (LoopMen_Time + 2000)) && (CurMen_Time <= (LoopMen_Time + 4000))) {
    lcd.setCursor(0, 0);
    lcd.print("System is");
    lcd.print("           ");
    lcd.setCursor(2, 1);
    if (waterState == true) {
      lcd.print("Watering");
    }
    if (waterState == false) {
      lcd.print("Not Watering");
    }
    lcd.print("           ");
  }
  if ((CurMen_Time > (LoopMen_Time + 4000)) && (CurMen_Time <= (LoopMen_Time + 6000))) {
    lcd.setCursor(0, 0);
    lcd.print("Zones Clogged:");
    lcd.print("           ");
    lcd.setCursor(2, 1);
    if ((z1Clog == false) && (z2Clog == false) && (z3Clog == false)) {
      lcd.print("NONE");
    }
    if (z1Clog == true) {
      lcd.print("1, ");
    }
    if (z2Clog == true) {
      lcd.print("2, ");
    }
    if (z3Clog == true) {
      lcd.print("3, ");
    }
    lcd.print("           ");
  }
  if ((CurMen_Time > (LoopMen_Time + 6000)) && (CurMen_Time <= (LoopMen_Time + 8000))) {
    lcd.setCursor(0, 0);
    lcd.print("Zones Leaking:");
    lcd.print("           ");
    lcd.setCursor(2, 1);
    if ((z1Leak == false) && (z2Leak == false) && (z3Leak == false)) {
      lcd.print("NONE");
    }
    if (z1Leak == true) {
      lcd.print("1, ");
    }
    if (z2Leak == true) {
      lcd.print("2, ");
    }
    if (z3Leak == true) {
      lcd.print("3, ");
    }
    lcd.print("           ");
  }
  //  if ((CurMen_Time > (LoopMen_Time+8000)) && (CurMen_Time <= (LoopMen_Time+10000))){
  //    lcd.setCursor(0,0);
  //    lcd.print("Fcast Updated:  ");
  //    lcd.setCursor(2,1);
  //    //lcd.print();
  //    lcd.print("           ");
  //  }
  if ((CurMen_Time > (LoopMen_Time + 10000)) && (CurMen_Time <= (LoopMen_Time + 12000))) {
    lcd.setCursor(0, 0);
    lcd.print("Rcast(0d,1d):   ");
    lcd.setCursor(2, 1);
    //if(fTemp1 != 999){
    lcd.print(fRain0);
    lcd.print(",");
    lcd.print(fRain1);
    //lcd.print("          ");
    //}
    lcd.print("           ");
  }
  if ((CurMen_Time > (LoopMen_Time + 12000)) && (CurMen_Time <= (LoopMen_Time + 14000))) {
    lcd.setCursor(0, 0);
    lcd.print("Tcast(1h,2h,3h):");
    lcd.setCursor(2, 1);
    //if(fTemp1 != 999){
    lcd.print((int)fTemp1);
    lcd.print(",");
    lcd.print((int)fTemp2);
    lcd.print(",");
    lcd.print((int)fTemp3);
    lcd.print("      ");
    //}
    //if(fTemp1 == 999){
    //  lcd.print("  None          ");
    //}
  }
  else if (CurMen_Time > (LoopMen_Time + 14000)) {
    LoopMen_Time = millis();
    MenLoop = 0;
  }

}

//--------Level 3--------
void lvl3Zone() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Z1:");
        lcd.print(z1Temp, 2);
        lcd.print(" F   ");
        lcd.setCursor(3, 1);
        lcd.print(z1Flow, 3);
        lcd.print("gal/min   ");
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Z2:");
        lcd.print(z2Temp, 2);
        lcd.print(" F   ");
        lcd.setCursor(3, 1);
        lcd.print(z2Flow, 3);
        lcd.print("gal/min   ");
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Z3:");
        lcd.print(z3Temp, 2);
        lcd.print(" F   ");
        lcd.setCursor(3, 1);
        lcd.print(z3Flow, 3);
        lcd.print("gal/min   ");
        break;
    }
  }
}
void lvl3Man() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0: //Manual Purge
        if ((waterState == false) && (purgeState != 1)) {
          lcd.setCursor(0, 0);
          lcd.print("Starting Manual");
          lcd.setCursor(0, 1);
          lcd.print("Purge");
          purgeState = 0;
          Purge();
        }
        else if (waterState == true) {
          lcd.setCursor(0, 0);
          lcd.print("Failed to Purge");
          lcd.setCursor(0, 1);
          lcd.print("Can't interrupt");

        }
        break;
      case 1: //Manual Water
        if ((purgeState != 1) && (waterState == false)) {
          lcd.setCursor(0, 0);
          lcd.print("Starting Manual");
          lcd.setCursor(0, 1);
          lcd.print("Water");
          waterManual();
        }
        else if (purgeState != 1) {
          lcd.setCursor(0, 0);
          lcd.print("Failed to Water");
          lcd.setCursor(0, 1);
          lcd.print("Can't interrupt");
        }
        break;
      case 2: //Manual Water
        if ((purgeState != 1) && (waterState == false)) {
          lcd.setCursor(0, 0);
          lcd.print("Starting Manual");
          lcd.setCursor(0, 1);
          lcd.print("Water");
          waterManual();
        }
        else if (purgeState != 1) {
          lcd.setCursor(0, 0);
          lcd.print("Failed to Water");
          lcd.setCursor(0, 1);
          lcd.print("Can't interrupt");
        }
        break;
    }
  }
}
void lvl3Cal() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0: //Calibrate
        if ((purgeState != 1) && (waterState == false)) {
          lcd.setCursor(0, 0);
          lcd.print("Beginning");
          lcd.setCursor(0, 1);
          lcd.print("Calibration");
          waterManual();
          CalFlow = true;
        }
        else if (purgeState == 1) {
          lcd.setCursor(0, 0);
          lcd.print("Failed to Cal");
          lcd.setCursor(0, 1);
          lcd.print("Can't interrupt");
          CalFlow = false;
        }
        break;
      case 1: //Calibrate
        if ((purgeState != 1) && (waterState == false)) {
          lcd.setCursor(0, 0);
          lcd.print("Beginning");
          lcd.setCursor(0, 1);
          lcd.print("Calibration");
          waterManual();
          CalFlow = true;
        }
        else if (purgeState == 1) {
          lcd.setCursor(0, 0);
          lcd.print("Failed to Cal");
          lcd.setCursor(0, 1);
          lcd.print("Can't interrupt");
          CalFlow = false;
        }
        break;
      case 2: //Calibrate
        if ((purgeState != 1) && (waterState == false)) {
          lcd.setCursor(0, 0);
          lcd.print("Beginning");
          lcd.setCursor(0, 1);
          lcd.print("Calibration");
          waterManual();
          CalFlow = true;
        }
        else if (purgeState == 1) {
          lcd.setCursor(0, 0);
          lcd.print("Failed to Cal");
          lcd.setCursor(0, 1);
          lcd.print("Can't interrupt");
          CalFlow = false;
        }
        break;
    }
  }
}
void lvl3Water() { //604800000 ms in one week
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Set: Demo Interval");
        waterInt = 1 * 60 * 1000;
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Set to 1/Week");
        waterInt = 604800000 / 1;
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Set: 2/Week");
        waterInt = 604800000 / 2;
        break;
      case 3:
        lcd.setCursor(0, 0);
        lcd.print("Set: 3/Week");
        waterInt = 604800000 / 3;
        break;
      case 4:
        lcd.setCursor(0, 0);
        lcd.print("Set: 4/Week");
        waterInt = 604800000 / 4;
        break;
      case 5:
        lcd.setCursor(0, 0);
        lcd.print("Set: 5/Week");
        waterInt = 604800000 / 5;
        break;
    }
  }
}
void lvl3Bzz() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Buzzer: ");
        lcd.setCursor(2, 1);
        lcd.print("UNMUTED");
        BZZmute = false;
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Buzzer: ");
        lcd.setCursor(2, 1);
        lcd.print("MUTED");
        BZZmute = true;
        digitalWrite(BZZpin, LOW);
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Buzzer: ");
        lcd.setCursor(2, 1);
        lcd.print("TESTING");
        digitalWrite(BZZpin, HIGH);
        break;
    }
  }
}
void lvl3Menu() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl1) {
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
}
//--------Level 2--------
void lvl2Zone() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Zone Info:");
        lcd.setCursor(2, 1);
        lcd.print("Zone 1");
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Zone Info:");
        lcd.setCursor(2, 1);
        lcd.print("Zone 2");
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Zone Info:");
        lcd.setCursor(2, 1);
        lcd.print("Zone 3");
        break;
    }
  }
}
void lvl2Man() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0: //Manual Purge
        lcd.setCursor(0, 0);
        lcd.print("Manual Control:");
        lcd.setCursor(2, 1);
        lcd.print("Force Purge");
        break;
      case 1: //Manual Water
        lcd.setCursor(0, 0);
        lcd.print("Manual Control:");
        lcd.setCursor(2, 1);
        lcd.print("Force Water");
        break;
      case 2: //Manual Water
        lcd.setCursor(0, 0);
        lcd.print("Manual Control:");
        lcd.setCursor(2, 1);
        lcd.print("Force Water");
        break;
    }
  }
}
void lvl2Cal() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0: //Calibrate
        lcd.setCursor(0, 0);
        lcd.print("Calibration:");
        lcd.setCursor(2, 1);
        lcd.print("Calibrate Flow");
        break;
      case 1: //Calibrate
        lcd.setCursor(0, 0);
        lcd.print("Calibration:");
        lcd.setCursor(2, 1);
        lcd.print("Calibrate Flow");
        break;
      case 2: //Calibrate
        lcd.setCursor(0, 0);
        lcd.print("Calibration:");
        lcd.setCursor(2, 1);
        lcd.print("Calibrate Flow");
        break;
    }
  }
}
void lvl2Water() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week:");
        lcd.setCursor(2, 1);
        lcd.print("Demo Interval");
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week:");
        lcd.setCursor(2, 1);
        lcd.print("1");
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week:");
        lcd.setCursor(2, 1);
        lcd.print("2");
        break;
      case 3:
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week:");
        lcd.setCursor(2, 1);
        lcd.print("3");
        break;
      case 4:
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week:");
        lcd.setCursor(2, 1);
        lcd.print("4");
        break;
      case 5:
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week:");
        lcd.setCursor(2, 1);
        lcd.print("5");
        break;
    }
  }
}
void lvl2Bzz() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl2) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Turn Buzzer On");
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Turn Buzzer Off");
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Test Buzzer");
        digitalWrite(BZZpin, LOW);
        break;
    }
  }
}
void lvl2Menu() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl1) {
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
}
//--------Level 1--------
void lvl1Menu() {
  if (!lcdUpToDate) {
    lcdUpToDate = true;
    switch (lvl1) {
      case 0: //Zone info
        lcd.setCursor(0, 0);
        lcd.print("Zone Info");
        break;
      case 1: //Manual
        lcd.setCursor(0, 0);
        lcd.print("Manual Control");
        break;
      case 2: //Calibration
        lcd.setCursor(0, 0);
        lcd.print("Calibration");
        break;
      case 3: //Water/Week
        lcd.setCursor(0, 0);
        lcd.print("Waters/Week");
        break;
      case 4: //Buzzer
        lcd.setCursor(0, 0);
        lcd.print("Buzzer Settings");
        break;
    }
  }
}
//--------Core Loop--------
void MenuLoop() {
  IdleBttn();
  switch (curlvl) {
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
