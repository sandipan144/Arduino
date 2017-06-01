long motor_left[] = {6, 7};// left motor

long motor_right[] = {9, 10};// right motor


void setup() {
  // put your setup code here, to run once:
  for (long i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(1000);
  backward();
  delay(1000);
  
}
void backward() {
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 100);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 150);
  Serial.println("BackWard");
}

void forward() {
  analogWrite(motor_left[0], 150);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 100);
  analogWrite(motor_right[1], 0);
  Serial.println("Forward");
}

void right() {
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 0);
  Serial.println("Right");
}
