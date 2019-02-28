//Controle du moteur en indiquant l'angle voulu par communication série

#include <Servo.h>

#define COMMAND 9 
#define RIGHT 3
#define LEFT 4

#define R_TRIG 10
#define R_ECHO 11
#define L_TRIG 5
#define L_ECHO 6

Servo servo;

uint8_t angle=90;

void setup() {
	pinMode(R_TRIG, OUTPUT);
	pinMode(L_TRIG, OUTPUT);
	pinMode(R_ECHO, INPUT);
	pinMode(L_ECHO, INPUT);

  servo.attach(COMMAND);
  servo.write(angle);
  Serial.begin(9600);
}



void loop() {
	//int r=analogRead(RIGHT);
	//int l=analogRead(LEFT);

	digitalWrite(R_TRIG, LOW);
	delayMicroseconds(2);
	digitalWrite(R_TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(R_TRIG, LOW);
	int r=pulseIn(R_ECHO, HIGH);

	digitalWrite(L_TRIG, LOW);
	delayMicroseconds(2);
	digitalWrite(L_TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(L_TRIG, LOW);
	int l=pulseIn(L_ECHO, HIGH);


	angle= map(l-r,2000,-2000,0,180);
	servo.write(angle);
	// if (Serial.available() > 0) {
	// 	adapte_angle(Serial.read());
	// 	servo.write(angle);
	// 	Serial.println(angle);
 //  	}
  	
  	Serial.print(l-r);Serial.print(" ; ");Serial.println(angle);
  	delay(100);
}



void adapte_angle(char c){
	switch (c) {
	    case 'q':
	    	if(angle<180) angle=angle+10;
	      break;
	    case 'd':
	      	if(angle>0) angle=angle-10;
	      break;
	    case 'l':
	    	angle=180;
	      break;
	    case 'r':
	    	angle=0;
	      break;
	    case 'a':
	    	angle=90;
	      break;
	    default:
	      return;
	}
}