byte pinler[4]={D3,D2,D1,D0};
void setup() {
  // put your setup code here, to run once:
  pinMode(D8,INPUT); 
  pinMode(D4,OUTPUT); 

  for(byte i=0;i<4;i++)
    pinMode(pinler[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(D8)==HIGH)
  {
    for(byte i=0;i<4;i++)
    digitalWrite(pinler[i], !digitalRead(pinler[i]));
    //digitalWrite(D0,!digitalRead(D0));
  }
  delay(200);
}
