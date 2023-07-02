#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

const char *ssid = "********";                 
const char *password = "******";           

//sicaklik almak için
int ADC_okunan=0;           
float sensor_gerilim=0.0;   
float sicaklik=0.0;   

#define FIREBASE_HOST "********" 
#define FIREBASE_AUTH "************" 
//------------------------------------------------------------------------------------
void sicaklik_olc()
{
  ADC_okunan=analogRead(A0);              // ADC yi oku, A0 girişine bağlı LM35
  sensor_gerilim=(ADC_okunan*1000.0)/1023.0; 
  sicaklik=sensor_gerilim/10.0;
}
//---------------------------------------------------------------------
void setup() 
{
  Serial.begin(9600);                             
  delay(1000);
  Serial.println("Wifi agina baglaniliyor");

  WiFi.mode(WIFI_STA);                           
  WiFi.begin(ssid, password);                   


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

  //setup'ın tamamı wifi bağlantısı için
}
//------------------------------------------------------------------------------------
void loop() 
{
  // değer yazdırma
  
  sicaklik_olc(); 
  //Firebase.setFloat("*****", 19.05); 
  
  Firebase.setFloat("*******", sicaklik); 
  
  // handle error
  if (Firebase.failed()) { 
      Serial.print("yazdirma hatasi:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  Serial.print("Okunan sicaklik : ");
  Serial.println(Firebase.getFloat("*********")); 
  delay(1000);
}
