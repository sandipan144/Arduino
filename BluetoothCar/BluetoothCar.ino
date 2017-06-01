int motor_left[] = {A0, A1};
int motor_right[] = {A2, A3};
String data = "";
int BTstate = 2;
int i=0;
void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  if (digitalRead(BTstate) == LOW)
    stop1();
  if (Serial.available() > 0)
  {
    data = Serial.read();
  }
  if (data == "65")
    left();
  else if (data == "66")
  {
    i++;
    if(i==1)
    {
      delay(500);
      forward();
    }
    else
    forward();
  }
  else if (data == "67")
    right();
  else if (data == "68")
    backward();
  else if (data == "69")
    stop1();
  else if (data == "70")
    forward();

  //user defined functions
}
void forward()
{
  analogWrite(motor_left[0], 235);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 248);
  analogWrite(motor_right[1], 0);
  Serial.println("Forward");
}

void backward()
{
  analogWrite(motor_left[1], 235);
  analogWrite(motor_left[0], 0);
  analogWrite(motor_right[1], 248);
  analogWrite(motor_right[0], 0);
  Serial.println("Backward");
}

void right()
{
  analogWrite(motor_left[0], 150);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[1], 143);
  analogWrite(motor_right[0], 0);
  Serial.println("Right");
}

void left()
{
  analogWrite(motor_left[1], 150);
  analogWrite(motor_left[0], 0);
  analogWrite(motor_right[0], 143);
  analogWrite(motor_right[1], 0);
  Serial.println("Left");
}
void stop1()
{
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 255);
  analogWrite(motor_right[0], 255);
  analogWrite(motor_right[1], 255);
  Serial.println("Stop");
}

