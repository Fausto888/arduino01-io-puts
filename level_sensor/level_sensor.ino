#include <Ultrasonic.h>

Ultrasonic levelSensor = Ultrasonic(0, 2); //echo pin 0 trigger 2         

void setup() {       
  Serial.begin(9600);
  delay(1000);
  Serial.println("Leyendo el nivel de agua");
}

void loop() {
  long distancia = levelSensor.getLastMeasure();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
}
