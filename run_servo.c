#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <curses.h>

#define COMMAND 18 //essayer avec 12(PWM0) et 13(PWM1)

int main(void)
{
	wiringPiSetupGpio();
	pinMode(COMMAND,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);

	//Pulse width entre 1ms(angle min) et 2ms (angle max)  
	//Temps entre les pulses : quelque part entre 10ms et 20ms  

	//const int minPulseWidth = 1000;  //Min and max pulse widths in µs
	//const int maxPulseWidth = 2000; 
	int angle;
	while(1){
		printf("Dans un sens\n");
		for(angle=1023;angle>=0;angle-=16){
			pwmWrite(COMMAND,angle);
			delay(20);
		}

		printf("Et puis dans l'autre\n");
		for(angle=0;angle<1024;angle+=16){
			pwmWrite(COMMAND,angle);
			delay(5);
		}
	}
	return 0;
}
