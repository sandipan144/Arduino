int vout = A0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(vout, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ir = digitalRead(vout);

  Serial.println(ir);
}
