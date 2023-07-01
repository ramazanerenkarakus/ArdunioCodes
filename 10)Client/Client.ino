
#include <ESP8266WiFi.h>

const char* ssid = "*****";
const char* password = "*****";

const char* host = "egm.org";
String istemci= "/";
//*************************************************
void setup() {
  Serial.begin(9600);
  delay(1500);
  Serial.println("Wifi ağına bağlanılıyor.");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
}
//***********************************************
void loop() {
 WiFiClient istemci;
 if (!istemci.connect(host,80))
  {
    Serial.println("Sunucuya bağlanılamadı");
    delay(500);
    return;
  }
  Serial.println("Web sunucusuna bağlanıldı");

  istemci.print(String("GET")+ uzanti + "HTTP/1.1\r\n" + "Host: " + host + "\r\n"+" Connection: close\r\n\r\n");

  unsigned long zaman_asimi = millis();

  while(istemci.available()==0)
  {
  if(millis()-zaman_asimi>5000) 
  {
    Serial.println(">>> Zaman asimi");
    istemci.stop();
    delay(3000);//3 saniye 
    return;
    
    }
  }
}
