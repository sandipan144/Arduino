#include <EEPROM.h>

int left[] = {A0, A1}; //from backside
int right[] = {A2, A3};
int enA = 5;// enable for left
int enB = 6;//enable for right
int l2, l1, m, r1, r2;//ir sensors
int s;
char path[1024] = "";
char pathShort[1024] = "";

int switch1 = 9;

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
  pinMode(2, INPUT);//ir pins
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);//
  pinMode(9, INPUT);//switch
}
//movement
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
//

void readSensor() {
  //sensor values
  l2 = digitalRead(2);
  l1 = digitalRead(3);
  m = !digitalRead(4);
  r1 = digitalRead(7);
  r2 = digitalRead(8);
  s = 10000 * l2 + 1000 * l1 + 100 * m + 10 * r1 + r2;//total calculation
  //
  Serial.println("Current Sensor values->" + s);
}

void eepromWrite() {

}

void eepromRead() {

}

void blinkEnd() {

}



void loop() {
  readSensor();

  if (true) {
    //condition for line follower
    if (s == 100) {
      f();
    }
    else if (s == 110) {
      sr();
    }
    else if (s == 1100) {
      sl();
    }
    else if (s == 0) {
      //
    }
    else if (s == 111 || s == 1111) {
      r();
    }
    else if (s == 11100 || s == 11110) {
      l();
    }
    else if (s == 11111) {
      //
    }
  }
}
