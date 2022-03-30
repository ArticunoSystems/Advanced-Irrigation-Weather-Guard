void DPinSetup() {
  //Serial.begin(115200);
  pinMode(0,INPUT);
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  pinMode(21,INPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  pinMode(27,INPUT);
  pinMode(32,INPUT);
  pinMode(33,INPUT);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
}

void DPinLoop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(0)== HIGH){
    //Serial.println("0");
  }
  if(digitalRead(2)== HIGH){
    Serial.println("2");
  }
  if(digitalRead(4)== HIGH){
    Serial.println("4");
  }
  if(digitalRead(5)== HIGH){
    Serial.println("5");
  }
  if(digitalRead(12)== HIGH){
    Serial.println("12");
  }
  if(digitalRead(13)== HIGH){
    Serial.println("13");
  }
  if(digitalRead(14)== HIGH){
    Serial.println("14");
  }
  if(digitalRead(15)== HIGH){
    Serial.println("15");
  }
  if(digitalRead(16)== HIGH){
    Serial.println("16");
  }
  if(digitalRead(17)== HIGH){
    Serial.println("17");
  }
  if(digitalRead(18)== HIGH){
    Serial.println("18");
  }
  if(digitalRead(19)== HIGH){
    Serial.println("19");
  }
  if(digitalRead(21)== HIGH){
    Serial.println("21");
  }
  if(digitalRead(22)== HIGH){
    Serial.println("22");
  }
  if(digitalRead(23)== HIGH){
    Serial.println("23");
  }
  if(digitalRead(25)== HIGH){
    Serial.println("25");
  }
  if(digitalRead(26)== HIGH){
    Serial.println("26");
  }
  if(digitalRead(27)== HIGH){
    Serial.println("27");
  }
  if(digitalRead(32)== HIGH){
    Serial.println("32");
  }
  if(digitalRead(33)== HIGH){
    Serial.println("33");
  }
  if(digitalRead(34)== HIGH){
    Serial.println("34");
  }
  if(digitalRead(35)== HIGH){
    Serial.println("35");
  }
}
