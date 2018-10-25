//Programme de test pour les capteurs ultrasoniques
//Range max : 85cm, au delà les valeurs sont instables
 

const int TRIGGER_PIN=2;
const int ECHO_PIN=3;
int temps;
int tempsMoyen;
int distance;
int derniereDistance=0;
int i=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  digitalWrite(TRIGGER_PIN,LOW); 
}

void loop() {
  temps=0; //Reset du temps
  for (i=0;i<10;i++){ //Moyenne sur 10 mesures
    digitalWrite(TRIGGER_PIN,HIGH); //Impulsion de 10 µs sur "trigger"
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN,LOW);
    temps = pulseIn(ECHO_PIN,HIGH); //Durée de l'impulsion LOW_HIGH_LOW renvoyée par "echo"
    temps = constrain(temps,0,5000);//au delà de 5000µs, les valeurs sont instables
    Serial.println(temps);
    tempsMoyen += temps;
    delay(80); 
  }
  tempsMoyen = tempsMoyen/10; //temps moyen en µs
  distance = 0.34*temps/2; // distance moyenne en mm
  Serial.print("Temps = ");Serial.print(temps); Serial.print("ms ;         ");
  Serial.print("Distance = ");Serial.print(distance/10.0); Serial.println("cm ;");
  
  if ((derniereDistance-distance) >10) { //L'objet s'est rapproché d'au moins 1cm  
    Serial.println("Attention, un obstacle se rapproche !"); 
  }
  derniereDistance = distance; 
}
