byte pinler[8]={D7,D6,D5,D4,D3,D2,D1,D0}; //Çıkış Pinleri 
void setup() {
  // put your setup code here, to run once:
pinMode(D8,INPUT); 

for(byte i=0;i<8;i++) 
  pinMode(pinler[i],OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(D8)==HIGH) 
for(byte i=0;i<8;i++) 
  digitalWrite(pinler[i],HIGH); 
   
else
   for(byte i=0;i<8;i++) 
  digitalWrite(pinler[i],LOW); 

delay(200);
}

//Bu durumda d8 butonuna basılınca tüm ledleri yakıyor elimizi led'den çekince sönüyor.
