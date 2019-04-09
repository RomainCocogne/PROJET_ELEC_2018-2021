/*
	Code a mettre sur la raspberry

	permet de commander la voiture a distance avec le clavier
*/

/************ library **********/

#include <stdio.h>		
#include <stdlib.h>
#include <curses.h>		
#include <errno.h>
#include <wiringPi.h>	
#include <wiringSerial.h>

/*******************************/

/*********** macro *************/

#define FOR   22	#define BACK  23
#define SPEED 18	#define ANGLE 12 

/*******************************/

/******* initialisation *******/

//communication arduino
void init_serial(int *serial_port){
	if ((*serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0)	/* open serial port */
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
  }
}

//lib wiringPi
void init_wiringPi(){
	if (wiringPiSetupGpio () == -1)					/* initializes wiringPi setup */
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
  }
}

//mode des pins
void init_pin(){
	pinMode(FOR,OUTPUT);
	pinMode(BACK,OUTPUT);
	pinMode(ANGLE,OUTPUT);
	pinMode(SPEED,PWM_OUTPUT);
}

/*************************************/




/**************** main ***************/

int main (void){
	int serial_port;
	init_serial(&serial_port);
	init_wiringPi();
	initscr();

	int c;
	while(1){
		if(c = getch()){
			serialPuts(serial_port,c); //Envoie c par uart
		}
		delay(10);
	}

	return EXIT_SUCCESS;

}

/************************************/

