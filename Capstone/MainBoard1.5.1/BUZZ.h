unsigned long CurBz_Time, LoopBz_Time;
int BzIter;
int BZZpin = 13;
bool BZZmute = false;

void BuzzSetup(){
  pinMode(BZZpin, OUTPUT); //set Buzzer pin to output
  digitalWrite(BZZpin, LOW); //initiate with a low signal
}
void BuzzLoop(){
  CurBz_Time = millis();
  if((CurBz_Time >= (LoopBz_Time + 1000)) && (BZZmute != false)){ //Toggle every 1000ms(1s)
    LoopBz_Time = CurBz_Time;
    digitalWrite(BZZpin, !digitalRead(BZZpin));//Toggle Buzzer
    //BzIter++;
  }
  //if(BzIter >= 30){ //Exit after 30000ms(30s)
  //  digitalWrite(BZZpin, LOW);
  //}
}
