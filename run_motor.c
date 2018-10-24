//for the raspberry pi

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <wiringPi.h>


#define CW 22
#define CCW 23
#define SPEED 18


int main (void){
	wiringPiSetupGpio();
	pinMode(CW,OUTPUT);
	pinMode(CCW,OUTPUT);
	pinMode(SPEED,PWM_OUTPUT);

	digitalWrite(CW,HIGH);
	digitalWrite(CCW,LOW);
	
	
	int c;
	int speed=260;
	initscr();
	while(1){
	c = getch();
	delay(10);

	switch (c){
		case '8':
			if (speed<500) speed+=30;
			delay(5);
		break;
		case '2':
			if (speed>260) speed-=30;
			delay(5);
		break;
		case '6':
			digitalWrite(CW,HIGH);
			digitalWrite(CCW,LOW);
		break;
		case '4':
			digitalWrite(CW,LOW);
			digitalWrite(CCW,HIGH);
		break;
		//default:
		
	}
	pwmWrite(SPEED,speed);
}

	return EXIT_SUCCESS;
	
	
	
}
