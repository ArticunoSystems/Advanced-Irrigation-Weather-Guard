const int Output_Pin = 34;
const int LED = 23;
const int TmpPin = 35;

int Vout; //Output voltage from TMP36
float TMP36C; //Desired Temp in C
float TMP36F; //Desired Temp in F

volatile int  Pulse_Count;
unsigned int  Liter_per_min;
unsigned int  Gal_per_min;
unsigned int  flowRate;
unsigned long Current_Time, Loop_Time;

void Detect_Rising_Edge(){ 
   Pulse_Count++;
} 

void setup(){
   Serial.begin(115200);
   pinMode(Output_Pin, INPUT);
   attachInterrupt(Output_Pin, Detect_Rising_Edge, RISING);
   pinMode(LED,OUTPUT);
   Current_Time = millis();
   Loop_Time = Current_Time;
} 

void loop(){
  Current_Time = millis();
  if(Current_Time >= (Loop_Time + 1000)){
    Serial.println(digitalRead(LED));
    digitalWrite(LED, !digitalRead(LED));
    
    Loop_Time = Current_Time;
    Liter_per_min = (Pulse_Count / 5.5);
    Gal_per_min = (Liter_per_min / 3.785);
    flowRate = Gal_per_min;
    Pulse_Count = 0;
    Serial.print(flowRate, DEC);
    Serial.println(" Gal/min");
    
    Vout = analogRead(TmpPin);
    Serial.print("Vout: ");
    Serial.println(Vout);
    TMP36C = (Vout*0.083105)-50.3125;
    TMP36F = ((TMP36C*9)/5)+32;
    Serial.print("TMP36: ");
    Serial.print(TMP36F);
    Serial.println(" F");
  }

}
