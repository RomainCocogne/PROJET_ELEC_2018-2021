/*
	Code a mettre sur l arduino

	permet de commander la voiture a distance avec le clavier
*/

/************ library **********/

#include <Servo.h>

/*******************************/

/*********** macro *************/

//output
#define FOR   7		
#define SPEED 10
#define SERVO 5 
//input
#define IR_R  3		
#define IR_L  4

/*******************************/

/*********** variables *********/

//pour le servo
Servo servo;
int angle=90;
//pour le moteur
int speed=0;
/******************************/


void setup() {
//pin mode
	//output 						//input pas utiles ici
	pinMode (FOR  , OUTPUT);		pinMode (IR_R , INPUT );
  	pinMode (SPEED, OUTPUT);		pinMode (IR_L , INPUT );

//servoz
	servo.attach (SERVO);			servo.write(angle);
//moteur
	analogWrite(SPEED, speed);

//serial
	Serial.begin(9600); 			while(!Serial);
	Serial.write("___init ok___ \nStart runing motor.....\n");
}

/****************************************/

void loop() {
	if (Serial.available() > 0) {
		extract_data(Serial.read(),&speed,&angle);
		Serial.println(speed);
		Serial.println(angle);
  	}
  	command_car(speed,angle);
}

/***************************************/

/************* fonctions **************/

//traite les donnees recus par le serial
void extract_data(char c, int *speed, int *angle){
	switch (c) {
	    case 'z':		if(*speed<250 ) 	*speed=*speed+5;		break ;
	    case 's':		if(*speed>-250)     *speed=*speed-5; 	    break ;
	    case 'd':		if(*angle>0   ) 	*angle=*angle-10;		break ;
	    case 'q':		if(*angle<180 ) 	*angle=*angle+10;		break ;
	    case 'a':							*speed=0        ;		break ;
	    case 'e':							*angle=90       ;		break ;
	    default:													return;
	}
}

/*************/

//fait rouler la voiture
void command_car(int speed, int angle){

	servo.write(angle);
	if      (speed>0)		{digitalWrite(FOR, HIGH);}
	else if (speed<0)		{digitalWrite(FOR, LOW );	   
						 	 speed = -speed         ;}
	//analogWrite(SPEED, speed);
	digitalWrite(SPEED, HIGH);
  	delayMicroseconds(speed);
  	digitalWrite(SPEED, LOW);
  	delayMicroseconds(speed);
}