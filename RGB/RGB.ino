int rPin = 13;
int gPin = 12;
int bPin = 8;
int pot = A0;
int gButton = 7;
int bButton = 2;
char rVal, gVal, bVal;
void setup()

{

  pinMode(rPin, OUTPUT);

  pinMode(gPin, OUTPUT);

  pinMode(bPin, OUTPUT);

  pinMode(pot, INPUT_PULLUP);

  pinMode(gButton, INPUT_PULLUP);

  pinMode(bButton, INPUT_PULLUP);

  Serial.begin(9600);
}



void loop()

{
  int potValue = analogRead(pot);
  Serial.println(potValue);

  //Makes the potentiometer act as a switch by turning it on when potentiometer
  //reading is more than 500

  if (potValue < 500){
    rVal = LOW;
  }
  else
  {
    rVal = HIGH;
  }

  if (digitalRead(gButton) == HIGH){
    gVal = HIGH;
  }
  else
  {
    gVal = LOW;
  }

  if (digitalRead(bButton) == HIGH){
    bVal = HIGH;
  }
  else
  {
    bVal = LOW;
  }

  setColour(rVal, gVal, bVal);



}


void setColour(char red, char green, char blue)

{

  digitalWrite(rPin, red);

  digitalWrite(gPin, green);

  digitalWrite(bPin, blue);

}
