int LSensorPin = 2; //left sensor pin
int MSensorPin = 4; //middle sensor pin
int RSensorPin = 7; //right sensor pin

int LSensorValue = LOW;
int MSensorValue = LOW;
int RSensorValue = LOW;

int motor_left[] = {8, 9};
int motor_right[] = {10, 11};

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
  if (Serial.available() > 0)
  {
    data = Serial.read();
  }
  if (data == "65")
  {
    int lir = leftIR();
    int mir = middleIR();
    int rir = rightIR();

    if (mir < th)
    {
      if (lir > th && rir > th)
        forward();
      if (lir < th && rir < th)
        forward();
    }
    if (mir > th)
    {
      if (lir > th && rir < th)
        right();
      if (lir < th && rir > th)
        left();
    }
  }
  if(data=="66")
  {
    stop1();
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
  analogWrite(motor_left[0], 235);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 248);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Forward");
}

void backward()
{
  analogWrite(motor_left[1], 235);
  digitalWrite(motor_left[0], LOW);
  analogWrite(motor_right[1], 248);
  digitalWrite(motor_right[0], LOW);
  Serial.println("Backward");
}

void right()
{
  analogWrite(motor_left[0], 150);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 0);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Right");
}

void left()
{
  analogWrite(motor_left[0], 0);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 150);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Left");
}
void stop1()
{
  analogWrite(motor_left[0], 0);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 0);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Stop");
}

