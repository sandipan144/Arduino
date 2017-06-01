
long vccf = 3;
long trigf = 4;
long echof = 5;

long vccl = A5;
long trigl = 8;
long echol = 11;

long vccr = A4;
long trigr = 12;
long echor = 13;

long buz = 2;

long th = 297;

long leftIRSensor = A0;
int vccIRr = A1;
long rightIRSensor = A2;
int vccIRl = A3;

long motor_left[] = {6, 7};
long motor_right[] = {9, 10};


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

  long cmf1 = frontUltra();
  long cml1 = leftUltra();
  long cmr1 = rightUltra();
  long lir1 = leftIR();
  long rir1 = rightIR();
  /*if (cmf1 <= 5) {
    stop1();
    }
    else {
    if (cmf1 <= 18 && cml1 <= 11 && cmr1 >= 11) {
      right();
    }
    else if (cmf1 <= 18 && cml1 >= 11 && cmr1 <= 11) {
      left();
    }
    else if (cmf1 <= 11 && cml1 <= 11 && cmr1 <= 11) {
      if (cmf1 <= 41 && cmr1 <= 20 && cml1 <= 20) {
        backward();

      }
      else if (cmf1 >= 41 && cmr1 <= 20 && cml1 > 20) {
        analogWrite(motor_left[1], 125);
        digitalWrite(motor_left[0], LOW);
        analogWrite(motor_right[0], 0);
        digitalWrite(motor_right[1], LOW);
        Serial.println("Moving Back left");
      }
      else if (cmf1 >= 41 && cml1 <= 20 && cmr1 > 20) {
        analogWrite(motor_left[0], 0);
        digitalWrite(motor_left[1], LOW);
        analogWrite(motor_right[1], 125);
        digitalWrite(motor_right[0], LOW);
        Serial.println("Moving Back right");
      }
      else {

        backward();
      }
    }
    else {*/
  if (cmf1 > 20) {
    if (cmr1 <= 18 && cml1 <= 18)
      forward();
  }

  /*else {
    if (cml1 >20 || lir1 > th) {
      left();
    }
    if(cmr1>10) {
      right();

    }
    }*/

  else if (cmf1 <= 20 && cmr1 >= 20) {
    if (cmf1 < 20) {
      if (cmr1 > 10) {
        //stop1();
        right();
        //stop1();
        forward();

      }
       else {
       forward();
      }
    }
  }
  else if (cmf1 <= 20 && cml1 >= 20) {
    if (cmf1 < 20) {
      if (cml1 > 10) {
        //stop1();
        left();
        //stop1();

      }
      else {
        forward();
      }
    }
  }

  delay(200);
}
//user-defined functions

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
  analogWrite(motor_left[0], 159);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 186);
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
  analogWrite(motor_left[0], 110);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[1], 0);
  digitalWrite(motor_right[0], LOW);
  Serial.println("Right");
}
void trimright() {
  analogWrite(motor_left[0], 120);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[1], 136);
  digitalWrite(motor_right[0], LOW);
  Serial.println("Trim Right");
}
void left() {
  analogWrite(motor_left[1], 0);
  digitalWrite(motor_left[0], LOW);
  analogWrite(motor_right[0], 110);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Left");
}
void trimleft() {
  analogWrite(motor_left[1], 129);
  digitalWrite(motor_left[0], LOW);
  analogWrite(motor_right[0], 130);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Trim Left");
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
