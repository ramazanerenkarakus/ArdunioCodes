void setup() {
  // put your setup code here, to run once:
pinMode(D0,OUTPUT); //D0 pinini çıkış olarak ayarlamak için
pinMode(D1,OUTPUT); //İstemediğimiz portları çıkış olarak ayarladık.
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT); // Burada output olarak verdiğimiz bir led'i aşağıda komut verip çalıştırmaz isek sönük olarak kalır.
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0,HIGH);// led yak
  digitalWrite(D5,LOW);// Ters şekilde biri yanarken diğeri sönsün kodu
  delay(500);
  digitalWrite(D0,LOW); //led söndür
  digitalWrite(D5,HIGH);
  delay(500); //Belirli bir süre yanıp sönme durumu için zaman ayarlama
}
