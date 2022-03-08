#include <TaskScheduler.h>

Scheduler Buzzer;

void Buzzinit(){
  pinMode(1, OUTPUT); //set Buzzer pin to output
  digitalWrite(1, LOW); //initiate with a low signal
}

void BuzzToggle(){
  digitalWrite(1, !digitalRead(1));//Toggle Buzzer
}
Task Buzz(TASK_SECOND*2000 , 30, &BuzzToggle);

void BZsetup () {
  Serial.begin(115200);
  Serial.println("Scheduler TEST");
  Buzzer.init();
  Serial.println("Initialized scheduler");
  Buzzer.addTask(Buzz);
  Serial.println("added t1");
  delay(5000);
  
  Buzz.enable();

}

void BZloop(){
  Buzzer.execute();
}
