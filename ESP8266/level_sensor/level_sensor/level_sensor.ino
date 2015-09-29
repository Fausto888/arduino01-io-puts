#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <aREST.h>
#include <Ultrasonic.h>

#define LISTEN_PORT 80

Ultrasonic levelSensor = Ultrasonic(0, 2); //echo pin 0 trigger 2         
const char* ssid = "TW Hackaton";
const char* password = "1714060439";
WiFiServer server(LISTEN_PORT);
aREST rest = aREST();
int distancia = 0;

void setup() {       
  Serial.begin(9600);
  delay(1000);
  
  //Start Wifi
  Serial.println("Iniciando WIFI");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  //Start Server
  server.begin();
  Serial.println("Server started");

  //Set REST
  distancia = 0;
  rest.set_id("1");
  rest.set_name("level_sensor");
  rest.variable("distancia",&distancia);
  
  Serial.println("Leyendo el nivel de agua");
}

void loop() {
  distancia = levelSensor.getLastMeasure();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);
}
