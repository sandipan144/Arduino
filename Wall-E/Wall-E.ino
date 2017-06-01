long vccf = 3;
long trigf = 4; // front ultra sonic sensor
long echof = 5;

long vccl = A5;
long trigl = 8; // left ultra-sonic sensor
long echol = 11;

long vccr = A4;
long trigr = 12; // right ultra-sonic sensor
long echor = 13;

long buz = 2; //  buzzer

long th = 292;

long leftIRSensor = A0;
int vccIRr = A1;  // right ir sensor

long rightIRSensor = A2;
int vccIRl = A3; // left ir sensor

long motor_left[] = {6, 7};// left motor

long motor_right[] = {9, 10};// right motor

int i = 0;


void setup() {

  for (long i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  pinMode(buz, OUTPUT);
  pinMode(vccf, OUTPUT);
  pinMode(vccl, OUTPUT);
  pinMode(vccr, OUTPUT);
  pinMode(leftIRSensor, INPUT);
  pinMode(rightIRSensor, INPUT);
  pinMode(vccIRr, OUTPUT);
  pinMode(vccIRl, OUTPUT);

  digitalWrite(vccf, HIGH);
  analogWrite(vccl, 255);
  analogWrite(vccr, 255);
  analogWrite(vccIRr, 255);
  analogWrite(vccIRl, 255);
  Serial.begin(9600);
}

void loop()
{
  // sensor values
  long cmf1 = frontUltra();
  long cml1 = leftUltra();
  long cmr1 = rightUltra();
  long lir1 = leftIR();
  long rir1 = rightIR();
  //rest of the program...

  if (cmf1 > 14) {
    if (lir1 > th && rir1 < th)
    {
      if (lir1 > th && rir1 < th)
        forward();
      else if (lir1 < th )
        backleft();
      else if (rir1 < th)
        backright();
    }
    if (rir1 > th && lir1 < th)
    {
      if (rir1 > th && lir1 < th)
        forward();
      else if (rir1 < th)
        backleft();
      else if (lir1 < th)
        backright();
    }

  }
  else if (cmf1 <= 14 && cmr1 > 14) {
    right();
    i++;
  }
  else if (cmf1 <= 14 && cml1 > 14) {
    left();
    i++;
  }
  if ( i >= 5 && cmf1 > 75 && cml1 < 43) {
    right();
  }
  delay(300);
}

//user-defined funstion
void stop1() {
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 255);
  analogWrite(motor_right[0], 255);
  analogWrite(motor_right[1], 255);
  Serial.println("Stop");
  return;
}
void stop2() {
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 255);
  analogWrite(motor_right[0], 255);
  analogWrite(motor_right[1], 255);
  Serial.println("Stop Final");
  exit(0);
}

void forward() {
  analogWrite(motor_left[0], 135);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 161);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Forward");
}
void backward() {
  analogWrite(motor_left[1], 110);
  digitalWrite(motor_left[0], LOW);
  analogWrite(motor_right[1], 126);
  digitalWrite(motor_right[0], LOW);
  Serial.println("Backward");
}
void right() {
  analogWrite(motor_left[1], 0);
  digitalWrite(motor_left[0], LOW);
  analogWrite(motor_right[1], 200 );
  digitalWrite(motor_right[0], LOW);
  Serial.println("Right");
}
void backright() {
  analogWrite(motor_left[0], 130);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[1], 130);
  digitalWrite(motor_right[0], LOW);
  Serial.println("Back Right");
}
void left() {
  analogWrite(motor_left[0], 0);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 130);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Left");
}
void backleft() {
  analogWrite(motor_left[1], 128);
  digitalWrite(motor_left[0], LOW);
  analogWrite(motor_right[0], 0);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Back Left");
}
long leftIR() {
  long lir = analogRead(leftIRSensor);
  return lir;
}
long rightIR() {
  long rir = analogRead(rightIRSensor);
  return rir;
}
long frontUltra() {
  digitalWrite(vccf, HIGH);
  long durationf, cmf;
  pinMode(trigf, OUTPUT);
  digitalWrite(trigf, LOW);
  delayMicroseconds(3);
  digitalWrite(trigf, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigf, LOW);
  pinMode(echof, INPUT);
  durationf = pulseIn(echof, HIGH);
  cmf = durationf / 29 / 2;
  return cmf;
}
long leftUltra() {
  digitalWrite(vccl, HIGH);
  long durationl, cml;
  pinMode(trigl, OUTPUT);
  digitalWrite(trigl, LOW);
  delayMicroseconds(3);
  digitalWrite(trigl, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigl, LOW);
  pinMode(echol, INPUT);
  durationl = pulseIn(echol, HIGH);
  cml = durationl / 29 / 2;
  return cml;
}
long rightUltra() {
  digitalWrite(vccr, HIGH);
  long durationr, cmr;
  pinMode(trigr, OUTPUT);
  digitalWrite(trigr, LOW);
  delayMicroseconds(3);
  digitalWrite(trigr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigr, LOW);
  pinMode(echor, INPUT);
  durationr = pulseIn(echor, HIGH);
  cmr = durationr / 29 / 2;
  return cmr;
}
