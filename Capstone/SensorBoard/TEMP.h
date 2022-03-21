//Temperature Program designed around the TMP36 Low Voltage Temperature Sensor
//ESP32's ADC range is 0 to 4095 (0V to 3.3V)
//According to TMP36's datasheet, the acceptable Temp range is -40C to 125C

int TmpPin = 13; //Pin connection for TMP36
int Vout; //Output voltage from TMP36
int TMP36C; //Desired Temp in C
int TMP36F; //Desired Temp in F
int Temp;



void TempSetup() {
  pinMode(TmpPin, INPUT);
}

int TempLoop() {
  Vout = analogRead(TmpPin);
  //Serial.print("Vout: ");
  //Serial.println(Vout);
  TMP36C = ((165*Vout)/4095)-40;
  TMP36F = ((TMP36C*9)/5)+32;
  //Serial.print("TMP36: ");
  //Serial.print(TMP36F);
  //Serial.println(" F");
  return TMP36F;
}
