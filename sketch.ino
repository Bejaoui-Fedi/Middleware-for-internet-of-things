// Définition des broches
const int flamePin = 13; // Capteur de flamme branché sur la broche GPIO 13
const int buzzerPin = 12; // Buzzer branché sur la broche GPIO 12
const int ledPin = 14;    // LED branchée sur la broche GPIO 14

void setup() {
  Serial.begin(115200);   // Initialisation du port série
  
  pinMode(flamePin, INPUT);  // Le capteur est configuré en entrée
  pinMode(buzzerPin, OUTPUT); // Le buzzer est configuré en sortie
  pinMode(ledPin, OUTPUT);    // La LED est configurée en sortie
  
  Serial.println("Système de détection d'incendie armé.");
}

void loop() {
  // En général, un capteur de flamme envoie un niveau BAS (LOW) lorsqu'il détecte du feu
  int flameState = digitalRead(flamePin);

  if (flameState == LOW) { // Incendie détecté
    Serial.println("ALERTE INCENDIE");
    
    // Déclenchement de l'alerte pendant 5 secondes (5000 millisecondes)
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
      digitalWrite(buzzerPin, HIGH); // Allume le buzzer
      digitalWrite(ledPin, HIGH);    // Allume la LED
      delay(250);                    // Attend 250ms
      
      digitalWrite(buzzerPin, LOW);  // Éteint le buzzer
      digitalWrite(ledPin, LOW);     // Éteint la LED
      delay(250);                    // Attend 250ms (ce qui fait clignoter la LED et bipper le buzzer)
    }
    
    // S'assure que tout est bien coupé après les 5 secondes si la flamme est toujours présente
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  } else {
    // Pas d'incendie : tout est éteint
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  delay(100); // Petite pause pour stabiliser la boucle
}