int led=13;
int a;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  a=Serial.read();
  if(a=='H'){
    digitalWrite(led,HIGH);
  }
  if(a=='L'){
    digitalWrite(led,LOW);
  }
}
}
