int motor_left[] = {A0, A1};
int motor_right[] = {A2, A3};

int i = 1;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  for (int i = 0; i < 2; i++)
  {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  digitalWrite(12, HIGH);
  analogWrite(motor_left[0], 255);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 0);
}

void loop() {
  
}
