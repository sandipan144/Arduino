int led1=6; 
int led2=9; 
int led3=10; 
int led4=11; 
int pote=A5;  

void setup(){ 
 pinMode(led1,OUTPUT); 
 pinMode(led2,OUTPUT); 
 pinMode(led3,OUTPUT); 
 pinMode(led4,OUTPUT); 
 pinMode(pote,INPUT); 
 Serial.begin(9600);
} 

void loop(){ 
  int value = analogRead(pote); 
  Serial.println(value);
  if(value<254){ 
    analogWrite(led1,value); 
    analogWrite(led2,0); 
    analogWrite(led3,0); 
    analogWrite(led4,0); 
     
  } 
   
  if(value>254 and value<511){ 
    analogWrite(led2,254); 
    analogWrite(led3,0); 
    analogWrite(led4,0); 
  } 
   
  if(value>511 and value<765){ 
    analogWrite(led3,254); 
    analogWrite(led4,0); 
  } 
   
  if(value>765){ 
    analogWrite(led4,254); 
  } 
   
}
