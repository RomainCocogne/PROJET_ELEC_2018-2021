//Controle du moteur en indiquant l'angle voulu par communication série

#include <Servo.h>

#define COMMAND 9 

Servo servo;

uint8_t val=90;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10); //Pour gagner en rapidité
  servo.attach(COMMAND);
  servo.write(val);
  //Serial.println("Setup OK");
}

void loop() {
  if (Serial.available() > 0){
    char char_buffer[3] = {' ',' ',' '};
    Serial.readBytes(char_buffer,3);
    val = atoi(char_buffer);
    //Serial.print("Angle : ");Serial.println(val);
    servo.write(val);
   }
  delay(10);
}
