int gPin = 42;
int yPin = 2;
int rPin = 1;

int n = 0;
unsigned long pt = 0;
long interval = 1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(gPin, OUTPUT);
  //digitalWrite(gPin, HIGH);

  pinMode(yPin, OUTPUT);
  //digitalWrite(yPin, HIGH);

  pinMode(rPin, OUTPUT);
  //digitalWrite(rPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long t = millis();
  if (t - pt >= interval)
  {
    pt = t;
    n += 1;
  }

  if (n%3 == 1){
    digitalWrite(gPin, HIGH);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW);
  }
  else if (n%3 == 2){
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, HIGH);
    digitalWrite(rPin, LOW);
  }
  else{
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, HIGH);
  }

}
