#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "*******";       
const char *password = "******";  

ESP8266WebServer sunucu(80);        
//****************************************************************
void anasayfa() {
  
  String sayfa="<DOCTYPE html>";
        sayfa+="<html>";
        sayfa+="<body>";
        sayfa+="<h1>NodeMCU sunucusuna hoşgeldiniz</h1>";
        sayfa+="<a href=\"/ledyak\" LED yakma linki </a>";
        sayfa+="<a href=\"/ledsondur\" LED sondurme linki </a>";
        sayfa+="</body>";
        sayfa+="</html>";
        
  sunucu.send(200, "text/html",sayfa);
}
//****************************************************************
void led_yakma() {
    String sayfa="<DOCTYPE html>";
        sayfa+="<html>";
        sayfa+="<body>";
        sayfa+="<h1>Led yanıyor</h1>";
        sayfa+="<a href=\"/ledsondur\" LED sondurme linki </a>";
        sayfa+="</body>";
        sayfa+="</html>";
  sunucu.send(200, "text/html", sayfa);
  digitalWrite(D0,HIGH);
}
//****************************************************************
void led_sondur() {
  
    String sayfa="<DOCTYPE html>";
        sayfa+="<html>";
        sayfa+="<body>";
        sayfa+="<h1>Led sondu</h1>";
        sayfa+="<a href=\"/ledyak\" LED yakma linki </a>";
        sayfa+="</body>";
        sayfa+="</html>";
  sunucu.send(200, "text/html",sayfa);
  digitalWrite(D0,LOW);
}
//****************************************************************
void bilinmeyen() {
  sunucu.send(404, "text/html", "<h1>Sayfa Bulunamadi</h1>");
}
//****************************************************************
void setup() 
{
  pinMode(D0,OUTPUT);
  Serial.begin(9600);   
  Serial.println("Erisim noktasi baslatiliyor...");
  
  WiFi.softAP(ssid, password);    

  IPAddress myIP = WiFi.softAPIP();   
  Serial.print("Erisim noktasi IPsi: ");
  Serial.println(myIP);
  
  sunucu.on("/", anasayfa);
  sunucu.on("/ledyak",led_yakma);
  sunucu.on("/ledsondur",led_sondur);
  sunucu.onNotFound(bilinmeyen);
  sunucu.begin();
}
//****************************************************************
void loop() {
  sunucu.handleClient();            
}
