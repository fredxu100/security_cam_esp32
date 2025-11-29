#define R_PIN 1

int pirPin = 21;   // connect OUT to GPIO5
int pirState = 0;

void setup() {
  pinMode(R_PIN, OUTPUT);
  pinMode(pirPin, INPUT);
  
}

void loop() {
  /*unsigned long t = millis();
  int on = (sin(t/200.0) + 1.0) * 127.5;
  analogWrite(R_PIN, on);*/

  pirState = digitalRead(pirPin);

  digitalWrite(R_PIN, pirState);
  
  
}