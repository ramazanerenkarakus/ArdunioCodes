void setup() {
  // put your setup code here, to run once:
pinMode(D5,INPUT); 
pinMode(D0,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(D5)==HIGH) 
   digitalWrite(D0,HIGH); 
else
   digitalWrite(D0,LOW);

delay(200);
}
