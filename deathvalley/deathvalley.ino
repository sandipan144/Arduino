# define lth 870
# define fth 915

int RF_opin=12, RF_ipin=13;           //12-trigger
int distance;
int motor_left[] = {6, 5};
int motor_right[] = {10, 9};
void setup()
{
  Serial.begin(9600);
  pinMode(RF_opin,OUTPUT);          // RF trig pin
  pinMode(RF_ipin,INPUT);      //echo
  
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  
  for(int i = 0; i < 2; i++)
    {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
    }
}


void loop()
{
  int x,y;
distance=dist();
Serial.print(" distance= ");
Serial.println(dist());

Serial.print(" irrrrrr left     ");
x=analogRead(A4);
Serial.println(x);

Serial.print(" irrrrrr FRONT    ");
y=analogRead(A5);
Serial.print(y);

if((dist()>6.5)&&(y>fth))
{
left();
}
else if((y<fth))
{
  right();
}
//else if((dist()<6.5)&&(x>lth)) stop1();

else if((distance<5.8) && (y>fth))
{ 
    analogWrite(motor_left[0],180);                              // This is used to turn Right.2     
    analogWrite(motor_left[1],0); 
    analogWrite(motor_right[0],80);
    analogWrite(motor_right[1],0);
}
else if((distance>5.8) && (distance<6.5) && (y>fth))
{
    analogWrite(motor_left[0],80);                               // This is used to turn Left.2 
    analogWrite(motor_left[1],0); 
    analogWrite(motor_right[0],177);
    analogWrite(motor_right[1],0);
}


}




float dist()
{
  float cm, time;
  digitalWrite(RF_opin,LOW);
  delayMicroseconds(3);
  digitalWrite(RF_opin,HIGH);
  delayMicroseconds(10);
  digitalWrite(RF_opin,LOW);
  
  time=pulseIn(RF_ipin,HIGH);
  cm=(time/29)/2;
  return(cm);
  delay(100);
  
}


void left()
  {
    analogWrite(motor_left[0],56);                              //left turn
    analogWrite(motor_left[1],0); 
    analogWrite(motor_right[0],175);
    analogWrite(motor_right[1],0);
    Serial.println("Left");                                // This prints Right when the robot would actually turn Left.     
  }



void right()
  {
    analogWrite(motor_left[0],210);                              //right turn
    analogWrite(motor_left[1],0); 
    analogWrite(motor_right[1],200);
    analogWrite(motor_right[0],0);    
    Serial.println("Right");                               // This prints Right when the robot would actually turn Right.
  }
  
  void Moveforward()
  {
    analogWrite(motor_left[0],150);                             
    digitalWrite(motor_left[1],LOW); 
    analogWrite(motor_right[0],150);
    digitalWrite(motor_right[1],LOW);
    Serial.println("Forward");                                   // This prints Forward when the robot would actually go forward.
  }
  void stop1()
  {
    analogWrite(motor_left[0],0);                             
    analogWrite(motor_left[1],0); 
    analogWrite(motor_right[0],0);
    analogWrite(motor_right[1],0);
    Serial.println("Stop");                                   // This Stops the bot
  }
