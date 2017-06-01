void setup() {
  // put your setup code here, to run once:


  pinMode(12, OUTPUT);
  pinMode(9, INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5, HIGH);
  if (digitalRead(9) == HIGH)
  {
    digitalWrite(12, HIGH);
  }
  else if (digitalRead(9) == LOW)
  {
    digitalWrite(12, LOW);
  }
}
