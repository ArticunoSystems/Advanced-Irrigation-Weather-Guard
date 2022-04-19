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

int lvl1 = 0;
int lvl2 = 0;
int lvl3 = 0;
int lvl4 = 0;
int curlvl = 1; //0=default display, 

int UP = 25; //pin for UP button
int DOWN = 14; //pin for BACK button
int SEL = 27; //pin for SELECT button
int BACK = 26; //pin for BACK button

void UPbttn(){
  switch (curlvl){
    case 0:
      break;
    case 1: //level 1
      if(lvl1 > 0){
        lvl1 -=1;
      }
      break;
    case 2: //level 2
      if(lvl2 > 0){
        lvl2 -=1;
      }
      break;
    case 3: //level 3
      if(lvl3 > 0){
        lvl3 -=1;
      }
      break;
    case 4: //level 4
      if(lvl4 > 0){
        lvl4 -=1;
      }
      break;
  }
}
void DOWNbttn(){
  switch (curlvl){
    case 0:
      break;
    case 1: //level 1
      if(lvl1 < 4){
        lvl1 +=1;
      }
      break;
    case 2: //level 2
      if(lvl2 < 4){
        lvl2 +=1;
      }
      break;
    case 3: //level 3
      if(lvl3 < 4){
        lvl3 +=1;
      }
      break;
    case 4: //level 4
      if(lvl4 < 4){
        lvl4 +=1;
      }
      break;
  }
}
void SELbttn(){
  if(curlvl < 4){
    curlvl += 1;
  }
}
void BACKbttn(){
  if(curlvl > 0){
    curlvl -= 1;
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
