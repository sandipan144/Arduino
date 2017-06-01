int SensorPin=2;
int SensorValue=LOW;

void setup()
{
    pinMode(13,OUTPUT); 
    Serial.begin(9600);
}

void loop()
{

    pinMode(2,OUTPUT);

    digitalWrite(2,HIGH);

    delayMicroseconds(10);

    pinMode(2,INPUT);

    long time = micros();

    while (digitalRead(SensorPin) == HIGH && micros() - time < 3000);

    int diff = micros() - time;

    SensorValue=diff;

    if(Serial.available()>0);
    {
        Serial.println(SensorValue); 
    }
    delay(500);
}
