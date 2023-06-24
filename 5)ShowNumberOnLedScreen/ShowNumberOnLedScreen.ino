byte pinler[7]={D7,D6,D5,D4,D3,D2,D1};
void setup() {
  // put your setup code here, to run once:
    for(byte i=0; i<7;i++)
      pinMode(pinler[i],OUTPUT);  //D1....D7 pinlerini çıkış yaptık yani söndürdük
}

void loop() {
  // put your main code here, to run repeatedly:
    //1'i yaz
    digitalWrite(D7,LOW);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D4,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D1,LOW);
    delay(1000);

    //9'i yaz
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D3,LOW);
    digitalWrite(D2,HIGH);
    digitalWrite(D1,HIGH);
    delay(1000);

    //0'i yaz
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D1,LOW);
    delay(1000);

    //5'i yaz
    digitalWrite(D7,HIGH);
    digitalWrite(D6,LOW);
    digitalWrite(D5,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D3,LOW);
    digitalWrite(D2,HIGH);
    digitalWrite(D1,HIGH);
    delay(1000);
    
}
