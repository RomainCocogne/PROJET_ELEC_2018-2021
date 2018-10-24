//programme test ir sensors

//distances optenues: sol polytech: detecte a <1cm
//					  surface blanche: detectee entre 2.5cm et 3cm




int Sensor = 10; // Déclaration de la broche d'entrée du capteur
   
void setup ()
{
  Serial.begin(9600); // Sortie série à 9600 bauds
  pinMode (Sensor, INPUT) ; // Initialisation de la broche d'entrée du capteur
}
   
// Le programme lit l'état des broches du capteur et envoie l'information
// de détection (ou non) d'un obstacle dans la console. 
void loop ()
{
  bool val = digitalRead (Sensor) ; // Lecture de la valeur du signal
   
  if (val == HIGH) // Si un signal est détecté, la diode s'allume
  {
    Serial.println("Pas d'obstacle");
  }
  else
  {
    Serial.println("Obstacle detecte");
  }
  Serial.println("------------------------------------"); 
  delay(500); // pause de 500ms entre les mesures
}

//Test pour github
//Test n2
