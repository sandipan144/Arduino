#include <Servo.h>

Servo esc;
int throttlePin = A0;

void setup()
{
  Serial.begin(9600);
  esc.attach(9);
}

void loop()
{
  int throttle = analogRead(throttlePin);
  Serial.println(throttle);
  throttle = map(throttle, 0, 1023, 0, 179);
  esc.write(throttle);
}
