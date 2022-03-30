const int Output_Pin = 27;

volatile int  Pulse_Count;
float  Liter_per_min;
float  Gal_per_min;
float  flowRate;
unsigned long Current_Time, Loop_Time;

void Detect_Rising_Edge(){ 
   Pulse_Count++;
} 

void FlowSetup(){ 
   pinMode(Output_Pin, INPUT);
   attachInterrupt(27, Detect_Rising_Edge, RISING);
                                     
   Current_Time = millis();
   Loop_Time = Current_Time;
} 

void FlowLoop(){
   Current_Time = millis();
   if(Current_Time >= (Loop_Time + 3000)){
      Loop_Time = Current_Time;
      Liter_per_min = (Pulse_Count / 5.5);
      Gal_per_min = (Liter_per_min / 3.785);
      flowRate = Gal_per_min;
      Pulse_Count = 0;
      Serial.print(flowRate, 3);
      Serial.println(" Gal/min");
   }
}
