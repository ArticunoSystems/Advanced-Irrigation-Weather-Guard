int UPbuttonState;             // the current reading from the input pin
int DOWNbuttonState;             // the current reading from the input pin
int SELbuttonState;             // the current reading from the input pin
int BACKbuttonState;             // the current reading from the input pin
int lastUPButtonState = LOW;   // the previous reading from the input pin
int lastDOWNButtonState = LOW;   // the previous reading from the input pin
int lastSELButtonState = LOW;   // the previous reading from the input pin
int lastBACKButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

unsigned long CurBttn_Time;
unsigned long LoopBttn_Time;

int lvl1 = 0;
int lvl2 = 0;
int lvl3 = 0;
int lvl4 = 1;
int curlvl = 0; //0=default display, 

int UP = 25; //pin for UP button
int DOWN = 14; //pin for BACK button
int SEL = 27; //pin for SELECT button
int BACK = 26; //pin for BACK button

void UPbttn(){
  lcd.clear();
  LoopBttn_Time = CurBttn_Time;
  switch (curlvl){
    case 0:
      break;
    case 1: //level 1
      if(lvl1 > 0){
        lcd.clear();
        lvl1 -=1;
      }
      break;
    case 2: //level 2
      if(lvl2 > 0){
        lcd.clear();
        lvl2 -=1;
      }
      break;
    case 3: //level 3
      if(lvl3 > 1){
        lcd.clear();
        lvl3 -=1;
      }
      break;
  }
}
void DOWNbttn(){
  LoopBttn_Time = CurBttn_Time;
  switch (curlvl){
    case 0:
      break;
    case 1: //level 1
      if(lvl1 < 4){
        lcd.clear();
        lvl1 +=1;
      }
      break;
    case 2: //level 2
      if((lvl2 < 4)&&(lvl1 == 3)){
        lcd.clear();
        lvl2 +=1;
      }
      else if(lvl2 < 2){
        lcd.clear();
        lvl2 +=1;
      }
      break;
    case 3: //level 3
      if(lvl3 < 5){
        lcd.clear();
        lvl3 +=1;
      }
      break;
  }
}
void SELbttn(){
  LoopBttn_Time = CurBttn_Time;
  if(curlvl < 3){
    lcd.clear();
    curlvl += 1;
  }
}
void BACKbttn(){
  LoopBttn_Time = CurBttn_Time;
  if(curlvl > 0){
    lcd.clear();
    lvl2 = 0;
    curlvl -= 1;
  }
}

void IdleBttn(){
  CurBttn_Time = millis();
  if(CurBttn_Time > LoopBttn_Time +15000){
    Serial.println("Idle Menu");
    curlvl = 0;
    lvl1 = 0;
    lvl2 = 0;
    lvl3 = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Default Display");

    LoopBttn_Time = CurBttn_Time;
    //digitalWrite(BZZpin, LOW);
  }
}

void BTTNSetup(){
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(SEL, INPUT);
  pinMode(BACK, INPUT);
}

void BTTNLoop(){
  //----UP Button Debounce----
  int UPreading = digitalRead(UP);
  if (UPreading != lastUPButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (UPreading != UPbuttonState) {
      UPbuttonState = UPreading;
      if(UPbuttonState == HIGH){
        UPbttn();
      }
    }
  }
  lastUPButtonState = UPreading;

  //----DOWN Button Debounce----
  int DOWNreading = digitalRead(DOWN);
  if (DOWNreading != lastDOWNButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (DOWNreading != DOWNbuttonState) {
      DOWNbuttonState = DOWNreading;
      if(DOWNbuttonState == HIGH){
        DOWNbttn();
      }
    }
  }
  lastDOWNButtonState = DOWNreading;

  //----SELECT Button Debounce----
  int SELreading = digitalRead(SEL);
  if (SELreading != lastSELButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (SELreading != SELbuttonState) {
      SELbuttonState = SELreading;
      if(SELbuttonState == HIGH){
        SELbttn();
      }
    }
  }
  lastSELButtonState = SELreading;

  //----BACK Button Debounce----
  int BACKreading = digitalRead(BACK);
  if (BACKreading != lastBACKButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (BACKreading != BACKbuttonState) {
      BACKbuttonState = BACKreading;
      if(BACKbuttonState == HIGH){
        BACKbttn();
      }
    }
  }
  lastBACKButtonState = BACKreading;
}
