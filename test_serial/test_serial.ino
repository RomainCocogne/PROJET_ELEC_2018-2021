//test_serial.ino

void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}

void loop() {
	if (Serial.available() > 0) {
		char c=Serial.read();
		Serial.print(c);
	}
	delay(10);
}