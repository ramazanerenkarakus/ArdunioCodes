#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

const char *ssid = "*****";                 
const char *password = "******";           

#define FIREBASE_HOST "************" 
#define FIREBASE_AUTH "************" 
//------------------------------------------------------------------------------------
void setup() 
{
  Serial.begin(9600);                           
  delay(1000);
  Serial.println("Wifi agina baglaniliyor");

  WiFi.mode(WIFI_STA);                           
  WiFi.begin(ssid, password);                    

  //------- Wifi ağına bağlanıncaya kadar beklenilen kısım ------------
  while (WiFi.status() != WL_CONNECTED) 
  { 
    delay(500);                               
    Serial.print(".");                         
  }
  //-------------------------------------------------------------------

  Serial.println("");                           
  Serial.println("Bağlantı sağlandı...");       

  Serial.print("Alınan IP addresi: ");          
  Serial.println(WiFi.localIP());              
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  
}
//------------------------------------------------------------------------------------
void loop() 
{
  // değer yazdırma
  
  //Firebase.setFloat("**********", 19.05); 
  Firebase.setInt("*******", random(30,50)); 
  
  // handle error
  if (Firebase.failed()) { 
      Serial.print("yazdirma hatasi:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  Serial.print("Okunan sicaklik : ");
  Serial.println(Firebase.getFloat("202013172050"));
  delay(1000);
}
