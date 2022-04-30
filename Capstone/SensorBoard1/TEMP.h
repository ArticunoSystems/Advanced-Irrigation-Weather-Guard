//Temperature Program designed around the TMP36 Low Voltage Temperature Sensor
//ESP32's ADC range is 0 to 4095 (0V to 3.3V)
//According to TMP36's datasheet, the acceptable Temp range is -40C to 125C (.2V to 1.7V)
//relationship between C and V: C = 58*V + 28.4

int TmpPin = 35; //Pin connection for TMP36
float Vout; //Output voltage from TMP36
float TMP36C; //Desired Temp in C
float TMP36F; //Desired Temp in F
float Temp;
float volts;


void TempSetup() {
  pinMode(TmpPin, INPUT);
}

int TempLoop(){
  Vout = analogRead(TmpPin);
  if(Vout < 300){
    Vout = 4095;
  }
//  Serial.print("Vout: ");
//  Serial.println(Vout);
  volts = Vout*3300.0/4096.0;
  TMP36C = (volts-319.4)/10.0;
  TMP36F = (TMP36C*9.0/5.0)+32.0;
  
  //Serial.print("TMP36: ");
  //Serial.print(TMP36F);
  //Serial.println(" F");
  return TMP36F;



}
