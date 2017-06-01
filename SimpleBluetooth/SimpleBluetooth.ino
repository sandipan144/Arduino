char data = 0;            //Variable for storing received data
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
}
void loop()
{
  Serial.println("Available data = "+Serial.available());
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.println("Recieved data = "+data);          //Print Value inside data in Serial monitor
   }
}
