# define ilth 870
# define irth 915

# define fth 6
# define rth 6

int opin = 12, ipin = 13, RF_opin = 11, RF_ipin = 10; //12-trigger    13-echo
int distance1, distance2;
int motor_left[] = {6, 5};
int motor_right[] = {10, 9};
void setup()
{
  pinMode(A0, INPUT); //ir1 initialize
  pinMode(A1, INPUT); //ir2 initialize


  pinMode(opin, OUTPUT);         // RF trig pin
  pinMode(ipin, INPUT);     //echo

  pinMode(RF_opin, OUTPUT);         // RF trig pin
  pinMode(RF_ipin, INPUT);     //echo


  for (int i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  Serial.begin(9600);
}


void loop()
{
  int x, y;
  distance1 = dist1();
  distance2 = dist2();
  Serial.print(" distance= ");
  Serial.println(dist1());

  Serial.println(dist2());
  Serial.print(" irrrrrr left     ");
  x = analogRead(A0);
  Serial.println(x);

  Serial.print(" irrrrrr right    ");
  y = analogRead(A1);
  Serial.print(y);

  if (distance2 == rth)              //move forward
  {
    Moveforward();
  }
  else if ((distance2 > rth))              //trimright
  {
    trimright();
  }
  else if ((distance2 < rth))              //trimright
  {
    trimleft();
  }

else if ((distance2 > 10) && (distance1 <= 8))
  {
    right();
  }
  else if ((distance2 < fth) && (distance1 <rth))
  {
    left();
  }

  else if ((distance < 5.8) && (y > fth))
  {
    analogWrite(motor_left[0], 180);                             // This is used to turn Right.2
    analogWrite(motor_left[1], 0);
    analogWrite(motor_right[0], 80);
    analogWrite(motor_right[1], 0);
  }
  else if ((distance > 5.8) && (distance < 6.5) && (y > fth))
  {
    analogWrite(motor_left[0], 80);                              // This is used to turn Left.2
    analogWrite(motor_left[1], 0);
    analogWrite(motor_right[0], 177);
    analogWrite(motor_right[1], 0);
  }


}




float dist1()
{
  float cm1, time1;
  digitalWrite(opin, LOW);
  delayMicroseconds(3);
  digitalWrite(opin, HIGH);
  delayMicroseconds(10);
  digitalWrite(opin, LOW);

  time1 = pulseIn(ipin, HIGH);
  cm1 = (time1 / 29) / 2;
  return (cm1);
  delay(100);

}

float dist2()
{
  float cm2, time2;
  digitalWrite(RF_opin, LOW);
  delayMicroseconds(3);
  digitalWrite(RF_opin, HIGH);
  delayMicroseconds(10);
  digitalWrite(RF_opin, LOW);

  time2 = pulseIn(RF_ipin, HIGH);
  cm = (time2 / 29) / 2;
  return (cm2);
  delay(100);

}

void twist()
{
  analogWrite(motor_left[1], 220);                             //Twist turn
  analogWrite(motor_left[0], 0);
  analogWrite(motor_right[0], 220);
  analogWrite(motor_right[1], 0);
  Serial.println("Left");                                // Takes a twist turn
}

void left()
{
  analogWrite(motor_left[1], 150);                             //left turn
  analogWrite(motor_left[0], 0);
  analogWrite(motor_right[0], 210);
  analogWrite(motor_right[1], 0);
  Serial.println("Left");                                // This prints Right when the robot would actually turn Left.
}

void trimleft()
{
  analogWrite(motor_left[0], 150);                             //left turn
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 165);
  analogWrite(motor_right[1], 0);
  Serial.println("Left");                                // This prints Right when the robot would actually turn Left.
}

void right()
{
  analogWrite(motor_left[0], 210);                             //right turn
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[1], 150);
  analogWrite(motor_right[0], 0);
  Serial.println("Right");                               // This prints Right when the robot would actually turn Right.
}

void trimright()
{
  analogWrite(motor_left[0], 165);                             //right turn
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 150);
  analogWrite(motor_right[1], 0);
  Serial.println("Right");                               // This prints Right when the robot would actually turn Right.
}

void Moveforward()
{
  analogWrite(motor_left[0], 150);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 150);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Forward");                                   // This prints Forward when the robot would actually go forward.
}
void stop1()
{
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 255);
  analogWrite(motor_right[0], 255);
  analogWrite(motor_right[1], 255);
  Serial.println("Stop");                                   // This Stops the bot
}
