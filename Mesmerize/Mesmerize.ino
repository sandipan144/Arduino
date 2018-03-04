
#define leftFarSensor      2
#define leftNearSensor     3
#define middleSensor       4
#define rightNearSensor    7
#define rightFarSensor     8

int left[] = {A0, A1}; //from backside
int right[] = {A2, A3};
int enA = 5;// enable for left
int enB = 6;//enable for right

int leftNearReading;
int leftFarReading;
int middleReading;
int rightNearReading;
int rightFarReading;

int leftNudge;
int replaystage;
int rightNudge;

#define leapTime 200

#define led 13

char path[30] = {};
int pathLength;
int readLength;

void setup() {

  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(middleSensor, INPUT);
  pinMode(rightNearSensor, INPUT);
  pinMode(rightFarSensor, INPUT);

  Serial.begin(9600);
  for (int i = 0; i < 2; i++) {     //motor pins
    pinMode(left[i], OUTPUT);
    pinMode(right[i], OUTPUT);
  }
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(A4, OUTPUT);
  analogWrite(A4, HIGH);
  digitalWrite(led, HIGH);
  delay(1000);
}

void readSensors() {

  leftNearReading    = digitalRead(leftNearSensor);
  leftFarReading     = digitalRead(leftFarSensor);
  middleReading      = !digitalRead(middleSensor);
  rightNearReading   = digitalRead(rightNearSensor);
  rightFarReading    = digitalRead(rightFarSensor);

  // serial printing below for debugging purposes

  Serial.print("leftNearReading: ");
  Serial.println(leftNearReading);
  Serial.print("leftFarReading: ");
  Serial.println(leftFarReading);

  Serial.print("middleReading: ");
  Serial.println(middleReading);
  Serial.print("rightNearReading: ");
  Serial.println(rightNearReading);
  Serial.print("rightFarReading: ");
  Serial.println(rightFarReading);
  delay(200);
}

void loop() {

  readSensors();

  if (leftFarReading == 0 && rightFarReading == 0 && middleReading == 1 && leftNearReading == 0 && rightNearReading == 0 ) {
    straight();
  }
  else {
    leftHandWall();
  }

}

void leftHandWall() {

  if ( leftFarReading == 1 && rightFarReading == 1) {
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 255);
    analogWrite(left[1], 0);
    analogWrite(right[0], 255);
    analogWrite(right[1], 0);
    delay(leapTime);
    readSensors();

    if (leftFarReading  == 1 && rightFarReading == 1) {
      done();
    }
    if (leftFarReading == 0 && rightFarReading == 0) {
      turnLeft();
    }

  }

  if (leftFarReading == 1) { // if you can turn left then turn left
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 255);
    analogWrite(left[1], 0);
    analogWrite(right[0], 255);
    analogWrite(right[1], 0);
    delay(leapTime);
    readSensors();

    if (leftFarReading == 0 && rightFarReading == 0) {
      turnLeft();
    }
    else {
      done();
    }
  }

  if (rightFarReading == 1) {
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 255);
    analogWrite(left[1], 0);
    analogWrite(right[0], 255);
    analogWrite(right[1], 0);
    delay(30);
    readSensors();

    if (leftFarReading == 1) {
      delay(leapTime - 30);
      readSensors();

      if (rightFarReading == 1  && leftFarReading == 1) {
        done();
      }
      else {
        turnLeft();
        return;
      }
    }
    delay(leapTime - 30);
    readSensors();
    if (leftFarReading == 0 && middleReading == 0 && rightFarReading == 0) {
      turnRight();
      return;
    }
    path[pathLength] = 'S';
    Serial.println("s");
    pathLength++;
    Serial.print("Path length: ");
    Serial.println(pathLength);
    if (path[pathLength - 2] == 'B') {
      Serial.println("shortening path");
      shortPath();
    }
    straight();
  }
  readSensors();
  if (leftFarReading == 0 && middleReading == 0 && rightFarReading == 0 && leftNearReading == 0 && rightNearReading == 0) {
    turnAround();
  }

}
void done() {
  Serial.println("Stop");
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(left[0], 0);
  analogWrite(left[1], 0);
  analogWrite(right[0], 0);
  analogWrite(right[1], 0);
  replaystage = 1;
  path[pathLength] = 'D';
  pathLength++;
  while (digitalRead(leftFarSensor) > 255) {
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
  }
  delay(500);
  replay();
}

void turnLeft() {



  while (!digitalRead(middleSensor) == 1) {
    Serial.println("Forward");
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 255);
    analogWrite(left[1], 0);
    analogWrite(right[0], 0);
    analogWrite(right[1], 255);
    delay(2);
  }

  //  while (digitalRead(rightCenterSensor) < 200) {
  //    digitalWrite(leftMotor1, LOW);
  //    digitalWrite(leftMotor2, HIGH);
  //    digitalWrite(rightMotor1, HIGH);
  //    digitalWrite(rightMotor2, LOW);
  //    delay(2);
  //    digitalWrite(leftMotor1, LOW);
  //    digitalWrite(leftMotor2, LOW);
  //    digitalWrite(rightMotor1, LOW);
  //    digitalWrite(rightMotor2, LOW);
  //    delay(1);
  //  }

  if (replaystage == 0) {
    path[pathLength] = 'L';
    Serial.println("l");
    pathLength++;
    Serial.print("Path length: ");
    Serial.println(pathLength);
    if (path[pathLength - 2] == 'B') {
      Serial.println("shortening path");
      shortPath();
    }
  }
}

void turnRight() {


  while (!digitalRead(middleSensor) == 1) {
    Serial.println("Forward");
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 0);
    analogWrite(left[1], 255);
    analogWrite(right[0], 255);
    analogWrite(right[1], 0);
    delay(2);
  }
  //  while (digitalRead(rightCenterSensor) < 200) {
  //    digitalWrite(leftMotor1, HIGH);
  //    digitalWrite(leftMotor2, LOW);
  //    digitalWrite(rightMotor1, LOW);
  //    digitalWrite(rightMotor2, HIGH);
  //    delay(2);
  //    digitalWrite(leftMotor1, LOW);
  //    digitalWrite(leftMotor2, LOW);
  //    digitalWrite(rightMotor1, LOW);
  //    digitalWrite(rightMotor2, LOW);
  //    delay(1);
  //  }
  //  while (digitalRead(leftCenterSensor) < 200) {
  //    digitalWrite(leftMotor1, HIGH);
  //    digitalWrite(leftMotor2, LOW);
  //    digitalWrite(rightMotor1, LOW);
  //    digitalWrite(rightMotor2, HIGH);
  //    delay(2);
  //    digitalWrite(leftMotor1, LOW);
  //    digitalWrite(leftMotor2, LOW);
  //    digitalWrite(rightMotor1, LOW);
  //    digitalWrite(rightMotor2, LOW);
  //    delay(1);
  //  }

  if (replaystage == 0) {
    path[pathLength] = 'R';
    Serial.println("r");
    pathLength++;
    Serial.print("Path length: ");
    Serial.println(pathLength);
    if (path[pathLength - 2] == 'B') {
      Serial.println("shortening path");
      shortPath();
    }
  }

}

void straight() {
  if ( !digitalRead(middleSensor) == 0) {
    Serial.println("Forward");
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 255);
    analogWrite(left[1], 0);
    analogWrite(right[0], 255);
    analogWrite(right[1], 0);
    delay(1);
    return;
  }
  if (!digitalRead(middleSensor) == 0) {
    Serial.println("Forward");
    analogWrite(enA, 230);
    analogWrite(enB, 255);
    analogWrite(left[0], 255);
    analogWrite(left[1], 0);
    analogWrite(right[0], 255);
    analogWrite(right[1], 0);
    delay(1);
    return;
  }

  Serial.println("Forward");
  analogWrite(enA, 230);
  analogWrite(enB, 255);
  analogWrite(left[0], 255);
  analogWrite(left[1], 0);
  analogWrite(right[0], 255);
  analogWrite(right[1], 0);
  delay(4);

}

void turnAround() {
  //  digitalWrite(leftMotor1, HIGH);
  //  digitalWrite(leftMotor2, LOW);
  //  digitalWrite(rightMotor1, HIGH);
  //  digitalWrite(rightMotor2, LOW);
  //  delay(150);
  //  while (digitalRead(leftCenterSensor) < 255) {
  //    digitalWrite(leftMotor1, LOW);
  //    digitalWrite(leftMotor2, HIGH);
  //    digitalWrite(rightMotor1, HIGH);
  //    digitalWrite(rightMotor2, LOW);
  //    delay(2);
  //    digitalWrite(leftMotor1, LOW);
  //    digitalWrite(leftMotor2, LOW);
  //    digitalWrite(rightMotor1, LOW);
  //    digitalWrite(rightMotor2, LOW);
  //    delay(1);
  //  }
  //  path[pathLength] = 'B';
  //  pathLength++;
  //  straight();
  //  Serial.println("b");
  //  Serial.print("Path length: ");
  //  Serial.println(pathLength);
}

void shortPath() {
  int shortDone = 0;
  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'R') {
    pathLength -= 3;
    path[pathLength] = 'B';
    Serial.println("test1");
    shortDone = 1;
  }

  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'S' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'R';
    Serial.println("test2");
    shortDone = 1;
  }

  if (path[pathLength - 3] == 'R' && path[pathLength - 1] == 'L' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'B';
    Serial.println("test3");
    shortDone = 1;
  }


  if (path[pathLength - 3] == 'S' && path[pathLength - 1] == 'L' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'R';
    Serial.println("test4");
    shortDone = 1;
  }

  if (path[pathLength - 3] == 'S' && path[pathLength - 1] == 'S' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'B';
    Serial.println("test5");
    shortDone = 1;
  }
  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'L' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'S';
    Serial.println("test6");
    shortDone = 1;
  }

  path[pathLength + 1] = 'D';
  path[pathLength + 2] = 'D';
  pathLength++;
  Serial.print("Path length: ");
  Serial.println(pathLength);
  printPath();
}




void printPath() {
  Serial.println("+++++++++++++++++");
  int x;
  while (x <= pathLength) {
    Serial.println(path[x]);
    x++;
  }
  Serial.println("+++++++++++++++++");
}


void replay() {
  //  readSensors();
  //  if (leftFarReading == 0 && rightFarReading == 0) {
  //    straight();
  //  }
  //  else {
  //    if (path[readLength] == 'D') {
  //      digitalWrite(leftMotor1, HIGH);
  //      digitalWrite(leftMotor2, LOW);
  //      digitalWrite(rightMotor1, HIGH);
  //      digitalWrite(rightMotor2, LOW);
  //      delay(100);
  //      digitalWrite(leftMotor1, LOW);
  //      digitalWrite(leftMotor2, LOW);
  //      digitalWrite(rightMotor1, LOW);
  //      digitalWrite(rightMotor2, LOW);
  //      endMotion();
  //    }
  //    if (path[readLength] == 'L') {
  //      digitalWrite(leftMotor1, HIGH);
  //      digitalWrite(leftMotor2, LOW);
  //      digitalWrite(rightMotor1, HIGH);
  //      digitalWrite(rightMotor2, LOW);
  //      delay(leapTime);
  //      turnLeft();
  //    }
  //    if (path[readLength] == 'R') {
  //      digitalWrite(leftMotor1, HIGH);
  //      digitalWrite(leftMotor2, LOW);
  //      digitalWrite(rightMotor1, HIGH);
  //      digitalWrite(rightMotor2, LOW);
  //      delay(leapTime);
  //      turnRight();
  //    }
  //    if (path[readLength] == 'S') {
  //      digitalWrite(leftMotor1, HIGH);
  //      digitalWrite(leftMotor2, LOW);
  //      digitalWrite(rightMotor1, HIGH);
  //      digitalWrite(rightMotor2, LOW);
  //      delay(leapTime);
  //      straight();
  //    }
  //
  //    readLength++;
  //  }
  //
  //  replay();

}

void endMotion() {
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(500);
  endMotion();
}
