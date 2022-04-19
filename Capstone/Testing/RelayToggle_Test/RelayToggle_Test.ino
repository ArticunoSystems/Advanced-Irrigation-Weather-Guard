int pin = 16;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(pin));
  digitalWrite(pin, !digitalRead(pin));
  delay(1000);
}
