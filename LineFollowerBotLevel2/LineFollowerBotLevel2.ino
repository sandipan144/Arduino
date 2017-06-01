int LSensorPin = 2; //left sensor pin
int MSensorPin = 4; //middle sensor pin
int RSensorPin = 9; //right sensor pin

int LSensorValue = LOW;
int MSensorValue = LOW;
int RSensorValue = LOW;

int motor_left[] = {A0, A1};
int motor_right[] = {A2, A3};

int th = 1504;

String data = "";
int BTstate = 2;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  for (int i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  digitalWrite(12, HIGH);
}

void loop() {
  int lir = leftIR();
  int mir = middleIR();
  int rir = rightIR();
  //    Serial.print(lir);
  //    Serial.print(mir);
  //    Serial.print(rir);
  //    Serial.println();
  if (mir < th)
  {
    if (lir > th && rir > th)
    {
      forward();
    }
    if (lir < th && rir > th)
    {
      left();
    }
    if (lir > th && rir < th)
    {
      right();
    }
    if (lir < th && rir < th)
    {
      forward();
    }
  }
  if (mir > th)
  {
    if (lir < th && rir < th)
    {
      forward();
    }
    if (lir > th && rir < th)
    {
      right();
    }
    if (lir < th && rir > th)
    {
      left();
    }
    if (lir > th && rir > th)
    {
      //forward();
    }
  }
}

int leftIR()
{

  pinMode(LSensorPin, OUTPUT);
  digitalWrite(LSensorPin, HIGH);
  delayMicroseconds(10);
  pinMode(LSensorPin, INPUT);
  long time = micros();
  while (digitalRead(LSensorPin) == HIGH && micros() - time < 3000);
  int diff = micros() - time;
  LSensorValue = diff;
  return LSensorValue;
}

int middleIR()
{

  pinMode(MSensorPin, OUTPUT);
  digitalWrite(MSensorPin, HIGH);
  delayMicroseconds(10);
  pinMode(MSensorPin, INPUT);
  long time = micros();
  while (digitalRead(MSensorPin) == HIGH && micros() - time < 3000);
  int diff = micros() - time;
  MSensorValue = diff;
  return MSensorValue;
}

int rightIR()
{

  pinMode(RSensorPin, OUTPUT);
  digitalWrite(RSensorPin, HIGH);
  delayMicroseconds(10);
  pinMode(RSensorPin, INPUT);
  long time = micros();
  while (digitalRead(RSensorPin) == HIGH && micros() - time < 3000);
  int diff = micros() - time;
  RSensorValue = diff;
  return RSensorValue;
}

void forward()
{
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 255);
  analogWrite(motor_right[1], 0);
  Serial.println("Forward");
}

void right()
{
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 0);
  Serial.println("Right");
}

void left()
{
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 255);
  analogWrite(motor_right[1], 0);
  Serial.println("Left");
}
void stop1()
{
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 0);
  Serial.println("Stop");
}

