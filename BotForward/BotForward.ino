int motor_left[] = {8, 9};
int motor_right[] = {10, 11};
String data="";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  for(int i = 0; i < 2; i++)
    {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
    }
    digitalWrite(12,HIGH);

}

void loop() {
 forward();
}
void forward()
{
  analogWrite(motor_left[0], 255);
  digitalWrite(motor_left[1], LOW);
  analogWrite(motor_right[0], 255);
  digitalWrite(motor_right[1], LOW);
  Serial.println("Forward");
}

