//run_motor.ino

//for the arduino

#define CW 7
#define CCW 8
#define SPEED 9

int speed;

void setup() {
  	Serial.begin(9600);
	pinMode(CW, OUTPUT);
  	pinMode(CCW, OUTPUT);
  	pinMode(SPEED, OUTPUT);

	digitalWrite(CW, HIGH);
	digitalWrite(CCW, LOW);
  	speed=0;
  	analogWrite(SPEED, speed);

  	Serial.write("___init ok___ \nStart runing motor.....\n");
}

void loop() {
	if (Serial.available() > 0) {
		adapte_vitesse(Serial.read());
		analogWrite(SPEED, speed);
		Serial.println(speed);
  	}
}


void adapte_vitesse(char c){
	switch (c) {
	    case '8':
	    	if(speed<245) speed=speed+10;
	      break;
	    case '2':
	      	if(speed>0) speed=speed-10;
	      break;
	    case '6':
	    	digitalWrite(CW, HIGH);
	    	digitalWrite(CCW, LOW);
	      break;
	    case '4':
	    	digitalWrite(CCW, HIGH);
	    	digitalWrite(CW, LOW);
	      break;
	    default:
	      return;
	}
}