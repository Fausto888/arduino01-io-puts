#include <ESP8266WiFi.h>
#include <WiFiClient.h>

void setup(void)
{  
  Serial.begin(9600);
  delay(1000);
  Serial.println("Conectandose a: ");
  Serial.println("TW Hackaton");
  WiFi.begin("TW Hackaton", "1714060439");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" [OK]"); 
  Serial.println("Mi IP: "); 
  Serial.println(WiFi.localIP());
}


void loop() {
  Serial.println("Conectandose en 5 segundos");
  delay(5000);
  
  WiFiClient wifiClient;
  Serial.print("Conectandose a: 192.168.1.146 ....");
  bool returnValue = wifiClient.connect("192.168.1.146", 3000);
  delay(5000);
  if (returnValue)
    Serial.println("[OK]");
  else
    Serial.println("[ERROR]"); 
  
  
  wifiClient.println("POST /contador/personas/ HTTP/1.1");
  wifiClient.println("Host: 192.168.1.146");
  wifiClient.println("User-Agent: Arduino/1.0");
  wifiClient.println("Connection: close");
  wifiClient.println("Content-Type: application/json");
  wifiClient.println("Content-Length: 31");
  wifiClient.println("");
  wifiClient.println("{distancia: '2.0', estado: '1'}");
  wifiClient.println("");
  wifiClient.println(""); 
  
  delay(5000);
  
  String returnedString;
  while(wifiClient.available()) {
    returnedString = wifiClient.readStringUntil('\r');
    wifiClient.print("Recibido: ");
    wifiClient.println(returnedString);
  }
  
  
  while (true) {
    delay(1000);
  }
}

