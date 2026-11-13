#include <ESP32Servo.h>

Servo monServo;          // Crée un objet pour le servomoteur
const int potPin = 34;   // Le potentiomètre est branché sur la broche ADC GPIO 34
const int servoPin = 18; // Le servomoteur est branché sur la broche GPIO 18

void setup() {
  Serial.begin(115200);  // Initialise la communication série pour afficher les messages
  
  // Nécessaire pour autoriser l'utilisation des timers PWM sur ESP32
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  monServo.setPeriodHertz(50);          // Fréquence standard de 50Hz pour les servomoteurs
  monServo.attach(servoPin, 500, 2400); // Attache le servo avec les largeurs d'impulsion min/max
}

void loop() {
  int valPot = analogRead(potPin);          // Lit la valeur du potentiomètre (0 à 4095 sur l'ESP32)
  int angle = map(valPot, 0, 4095, 0, 180); // Convertit la plage 0-4095 en un angle de 0 à 180°
  
  monServo.write(angle);                    // Envoie l'angle au servomoteur

  // Affichage des valeurs dans le Moniteur Série
  Serial.print("Valeur Potentiomètre : ");
  Serial.print(valPot);
  Serial.print(" | Angle Servo : ");
  Serial.print(angle);
  Serial.println(" °");

  delay(50);                                // Petite pause (augmentée à 50ms pour que l'affichage reste lisible)
}