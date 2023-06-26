#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESP_*****";
const char *password = "*****"; 

ESP8266WebServer sunucu(80); 
//***************************************************
void anasayfa() {
  sunucu.send(200, "text/html", "<h1>Baglandiniz</h1>");
}
//**************************************************
void setup() {
  Serial.begin(9600); 
  Serial.print("Erişim noktası başlatılıyor....");

  WiFi.softAP(ssid, password); // erisim noktası olarak baslat

  IPAddress myIP = WiFi.softAPIP(); // for ıp address
  Serial.print("Erisim noktası IPsi: ");
  Serial.println(myIP);
  
  sunucu.on("/", anasayfa); 
  sunucu.begin(); 
}

void loop() {
  sunucu.handleClient();
}
