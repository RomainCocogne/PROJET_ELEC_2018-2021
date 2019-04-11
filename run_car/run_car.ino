//Controle du moteur en indiquant l'angle voulu par communication série

#include <Servo.h>

#define SERVO 5
#define IR_RIGHT 3
#define IR_LEFT 4
#define FOR   7    
#define SPEED 10

//#define R_TRIG 10
//#define R_ECHO 11
//#define L_TRIG 5
//#define L_ECHO 6

Servo servo;

const int speed = 150;
uint8_t angle=90;

void setup() {
    //output            //input 
  pinMode (FOR  , OUTPUT);    pinMode (IR_RIGHT , INPUT );
  pinMode (SPEED, OUTPUT);    pinMode (IR_LEFT , INPUT );

//servo
  servo.attach (SERVO);     
  servo.write(angle);
//moteur
  //analogWrite(SPEED, speed);

//serial
//  Serial.begin(9600);       
//  while(!Serial);
//  Serial.write("___init ok___ \nStart runing motor.....\n");
}



void loop() {

  //Get ir sensors data
	int r=analogRead(IR_RIGHT);
	int l=analogRead(IR_LEFT);

  //Process angle value
	angle= map((r-l),1024,-1024,0,180);
//  Serial.print(l-r);Serial.print(" ; ");Serial.println(angle);

  //Run the motor
  command_car(speed, angle);
}


void command_car(int speed, uint8_t angle){

  servo.write(angle);
  if      (speed>0)   {digitalWrite(FOR, HIGH);}
  else if (speed<0)   {digitalWrite(FOR, LOW );    
               speed = -speed         ;}
//  analogWrite(SPEED, speed);
  digitalWrite(SPEED, HIGH);
    delayMicroseconds(speed);
    digitalWrite(SPEED, LOW);
    delayMicroseconds(speed);
}

//
//void adapte_angle(char c){
//	switch (c) {
//	    case 'q':
//	    	if(angle<180) angle=angle+10;
//	      break;
//	    case 'd':
//	      	if(angle>0) angle=angle-10;
//	      break;
//	    case 'l':
//	    	angle=180;
//	      break;
//	    case 'r':
//	    	angle=0;
//	      break;
//	    case 'a':
//	    	angle=90;
//	      break;
//	    default:
//	      return;
//	}
//}
