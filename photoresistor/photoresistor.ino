const int photoResistor = A0;
const int relayOutput = 13;

int photoResistorValue;

void setup() {
    pinMode(relayOutput, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photoResistorValue = analogRead(photoResistor);
  Serial.print(photoResistorValue);
  if (photoResistorValue > 500) {
    digitalWrite(relayOutput, HIGH);
  } 
  else {
    digitalWrite(relayOutput, LOW);
  }
  delay(10);
}
