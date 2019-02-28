//Controle du moteur en indiquant l'angle voulu par communication série

#include <Servo.h>

#define COMMAND 9 
#define RIGHT 5
#define LEFT 4

Servo servo;

uint8_t angle=90;

void setup() {
  servo.attach(COMMAND);
  servo.write(angle);
  Serial.begin(9600);
}

void loop() {
	int r=analogRead(RIGHT);
	int l=analogRead(LEFT);

	angle= map(l-r,1024,-1024,0,180);
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