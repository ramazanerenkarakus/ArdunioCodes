#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "*********";
const char *password = "*******"; 
int ADC_okunan=0;           
float sensor_gerilim=0.0;   
float sicaklik=0.0;

ESP8266WebServer sunucu(80); 
//***************************************************
void anasayfa() {
  sicaklik_olc();
  sunucu.send(200, "text/html", "<h1>Baglandiniz. Sicaklik degeri:"+String(sicaklik)+"</h1>");
}
//**************************************************

void led_yakma() {
  sunucu.send(200, "text/html", "<h1>Led yaniyor!</h1>");
  digitalWrite(D0,HIGH);
}
//**************************************************
void led_sondur() {
  sunucu.send(200, "text/html", "<h1>Led sondu!</h1>");
  digitalWrite(D0,LOW);
}
//**************************************************
void bilinmeyen() {
  sunucu.send(404, "text/html", "<h1>Baglandiniz</h1>");
}
void sicaklik_olc(){
  ADC_okunan=analogRead(A0);              // ADC yi oku, A0 girişine bağlı LM35
  sensor_gerilim=(ADC_okunan*1000.0)/1023.0; 
  sicaklik=sensor_gerilim/10.0;
  }
//**************************************************
void setup() {
  pinMode(D0,OUTPUT);
  Serial.begin(9600);
  Serial.print("Erişim noktası başlatılıyor....");

  WiFi.softAP(ssid, password); 

  IPAddress myIP = WiFi.softAPIP(); 
  Serial.print("Erisim noktası IPsi: "); 
  Serial.println(myIP);
  
  sunucu.on("/", anasayfa); /
  sunucu.on("/ledyak",led_yakma);
  sunucu.on("/ledsondur",led_sondur);
  sunucu.onNotFound(bilinmeyen);
  sunucu.begin();
}

void loop() {
  sunucu.handleClient();
}
