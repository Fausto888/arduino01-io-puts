const int LED = 9;
int i = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
	for (i = 0; i < 255; i++) { // loop from 0 to 254 (fade in)
		analogWrite(LED, i);
		// set the LED brightness
		delay(10); // Wait 10ms because analogWrite
		// is instantaneous and we would
		// not see any change
	}
	
	for (i = 255; i > 0; i--) { // loop from 255 to 1 (fade out)
		analogWrite(LED, i); // set the LED brightness
		delay(10);
	// Wait 10ms
	}
}