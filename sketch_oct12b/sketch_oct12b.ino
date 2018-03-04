#include <EEPROM.h>
int address = 0;
void setup() {
  Serial.begin(9600);
  String data = "SUDFGHJKFGHHFCGVHBJNJBHJVHGCFXCVBN";
  String data1;
  EEPROM.get(address, data1);
  Serial.println(data1);
}

void loop() {
}
