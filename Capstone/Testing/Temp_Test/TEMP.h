//Temperature Program designed around the TMP36 Low Voltage Temperature Sensor
//ESP32's ADC range is 0 to 4095 (0V to 3.3V)
//According to TMP36's datasheet, the acceptable Temp range is -40C to 125C

int TmpPin = 13; //Pin connection for TMP36
int Vout; //Output voltage from TMP36
float TMP36C; //Desired Temp in C
float TMP36F; //Desired Temp in F


void TempSetup() {

}
void TempLoop() {
  Vout = analogRead(TmpPin);
  Serial.print("Vout: ");
  Serial.println(Vout);
  TMP36C = (Vout*0.083105)-50.3125;
  TMP36F = ((TMP36C*9)/5)+32;
  Serial.print("TMP36: ");
  Serial.print(TMP36F);
  Serial.println(" F");
}
