int left[] = {A0, A1}; //from backside
int right[] = {A2, A3};
int enA = 5;// enable for left
int enB = 6;//enable for right

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 2; i++) {     //motor pins
    pinMode(left[i], OUTPUT);
    pinMode(right[i], OUTPUT);
  }
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(A4, OUTPUT);
  analogWrite(A4, HIGH);
}

void f() {
  Serial.println("Forward");
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  analogWrite(left[0], 255);
  analogWrite(left[1], 0);
  analogWrite(right[0], 255);
  analogWrite(right[1], 0);
  
}

void u() {

}

void l() {
  Serial.println("Left");
  analogWrite(enA, 0);
  analogWrite(enB, 255);
  analogWrite(left[0], 255);
  analogWrite(left[1], 0);
  analogWrite(right[0], 255);
  analogWrite(right[1], 0);
  
}

void sl() {
  Serial.println("Straff Left");
  analogWrite(enA, 200);
  analogWrite(enB, 220);
  analogWrite(left[0], 255);
  analogWrite(left[1], 0);
  analogWrite(right[1], 255);
  analogWrite(right[0], 0);
  Serial.println("Straff Left");
}

void r() {
  Serial.println("Right");
  analogWrite(enA, 255);
  analogWrite(enB, 0);
  analogWrite(left[0], 255);
  analogWrite(left[1], 0);
  analogWrite(right[0], 255);
  analogWrite(right[1], 0);
  
}

void sr() {
  Serial.println("Straff Right");
  analogWrite(enA, 220);
  analogWrite(enB, 200);
  analogWrite(left[1], 255);
  analogWrite(left[0], 0);
  analogWrite(right[0], 255);
  analogWrite(right[1], 0);
  
}

void stop1() {
  Serial.println("Stop");
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  analogWrite(left[0], 1);
  analogWrite(left[1], 1);
  analogWrite(right[0], 1);
  analogWrite(right[1], 1);
  
}

void moveInch() {
  Serial.println("Move Inch");
  //move inch
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  analogWrite(left[0], 255);
  analogWrite(left[1], 0);
  analogWrite(right[0], 255);
  analogWrite(right[1], 0);
  //readSensor();
  delay(300);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  analogWrite(left[0], 0);
  analogWrite(left[1], 255);
  analogWrite(right[0], 0);
  analogWrite(right[1], 255);
  delay(300);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  analogWrite(left[0], 0);
  analogWrite(left[1], 0);
  analogWrite(right[0], 0);
  analogWrite(right[1], 0);
  delay(300);
}

void loop(){
  moveInch();
}

