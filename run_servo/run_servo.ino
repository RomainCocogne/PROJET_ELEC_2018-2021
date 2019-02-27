//Controle du moteur en indiquant l'angle voulu par communication série

#include <Servo.h>

#define COMMAND 9 

Servo servo;

uint8_t val=90;

void setup() {
  servo.attach(COMMAND);
  servo.write(val);
  Serial.begin(9600);
}

void loop() {
//  val = 0;
//  for (int i=0;i<10;i++){
     val = map(analogRead(5),900,0,90,180);
//  }
//  val = val/10;
  servo.write(val);
  Serial.print(analogRead(5));Serial.print(" ; ");Serial.println(val);
  delay(100);
}
