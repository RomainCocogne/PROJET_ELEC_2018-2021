//Controle du moteur en incrementant l'angle dans la direction voulue  

#include <Servo.h>

#define COMMAND 9 

Servo servo;

int16_t val=90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(COMMAND);
  servo.write(val);
  Serial.println("Setup OK");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    char c = Serial.read();
    changer_angle(c);
    Serial.print("Angle : ");Serial.println(val);
    servo.write(val);
   }
  delay(10);
}

void changer_angle(char c){
  switch(c){
    case '4' :
      val = constrain(val-10,0,180);
      break;
    case '6' :
      val = constrain(val+10,0,180); 
    default:
      break;
  }
}
