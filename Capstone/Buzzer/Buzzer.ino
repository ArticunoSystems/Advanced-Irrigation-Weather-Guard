#include <TaskScheduler.h>

void BuzzCallback();
Task Buzz(2000 , 30, &BuzzCallback);

Scheduler Buzzer;

void Buzzinit(){
  pinMode(1, OUTPUT); //set Buzzer pin to output
  digitalWrite(1, LOW); //initiate with a low signal
}

void BuzzCallback(){
  digitalWrite(1, HIGH); //turn on Buzzer
}

void setup () {
  Serial.begin(115200);
  Serial.println("Scheduler TEST");
  Buzzer.init();
  Serial.println("Initialized scheduler");
  Buzzer.addTask(Buzz);
  Serial.println("added t1");
  delay(5000);
  
  Buzz.enable();

}

void loop(){
  Buzzer.execute();
}
