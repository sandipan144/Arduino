int timer=100;
void setup() {
  int thisPin;
  for(thisPin=2;thisPin<7;thisPin++){
    pinMode(thisPin,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int thisPin;
  for(thisPin=2;thisPin<7;thisPin++){
    digitalWrite(thisPin,HIGH);
    delay(timer);
    digitalWrite(thisPin,LOW);
  }

  for(thisPin=6;thisPin>=2;thisPin--){
    digitalWrite(thisPin,HIGH);
    delay(timer);
    digitalWrite(thisPin,LOW);
  }

}
