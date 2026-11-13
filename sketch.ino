
#define GAS 34
#define LED 2
#define BUZZER 25

#define SEUIL_GAZ 2000

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  int gaz = analogRead(GAS);

  Serial.print("Niveau de gaz : ");
  Serial.println(gaz);

  if (gaz > SEUIL_GAZ) {

    Serial.println("ALERTE GAZ");

    unsigned long debut = millis();

    tone(BUZZER, 1000);

    while (millis() - debut < 5000) {
      digitalWrite(LED, HIGH);
      delay(250);
      digitalWrite(LED, LOW);
      delay(250);
    }

    noTone(BUZZER);
  }

  delay(500);
}
