int vcc = 2;
int trig = 3;
int echo = 4;
int gnd = 5;
int led = 13;
int buz = 12;
int dist = 70;
int distfalse=35;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode (vcc, OUTPUT);
  pinMode (gnd, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(vcc, HIGH);
  long duration, inches, cm;
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(3);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm > distfalse && cm<=dist) {
    ledbuz();
  }
  if(cm<= distfalse)
  {
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    delay(100);
  }

  delay(200);
}


//other fucion's
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void ledbuz() {
  int i = 0, j;
  if (i <= 0) {
    for (j = 1; j <= 4; j++,i++) {
      digitalWrite(led, HIGH);
      digitalWrite(buz, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      digitalWrite(buz, LOW);
      delay(100);
    }

  }
  if(i>0) {
    for (j = 1; j <= 15; j++) {
      digitalWrite(led, HIGH);
      digitalWrite(buz, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      digitalWrite(buz, LOW);
    }
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    delay(100);
    loop();
  }
}

