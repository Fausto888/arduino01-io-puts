const int LED = 13;
const int PB = 2;

int buttonState;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(PB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(PB);
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(LED, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LED, LOW); 
  }
  delay(10);
}
