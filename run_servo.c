#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <curses.h>

#define COMMAND 18 //essayer avec 12(PWM0) et 13(PWM1)

int main(void)
{
	wiringPiSetupGpio();
	pinMode(COMMAND,PWM_OUTPUT);

	int angle;
	while(1){
		printf("Dans un sens\n");
		for(angle=1023;angle>=0;angle--){
			pwmWrite(COMMAND,angle);
			delay(5);
		}

		printf("Et puis dans l'autre\n");
		for(angle=0;angle<1024;angle++){
			pwmWrite(COMMAND,angle);
			delay(5);
		}
	}
	return 0;
}
