#include <EEPROM.h>
char data;
String s;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //  Serial.println(EEPROM.length());
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data);
    s = s + data;
    Serial.println(s);
  }
}
