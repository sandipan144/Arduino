#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int led=13;
int a;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(0,0);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  a=Serial.read();
  if(a=='H'){
    digitalWrite(led,HIGH);
    lcd.println("High");
  }
  if(a=='L'){
    digitalWrite(led,LOW);
    lcd.println("Low");
  }
}

}
