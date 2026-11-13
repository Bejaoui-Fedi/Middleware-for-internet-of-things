#define LDR 34
#define LED 2
#define SEUIL 2000

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  int lumiere = analogRead(LDR);

  Serial.print("Luminosite : ");
  Serial.println(lumiere);

  if (lumiere > SEUIL) {
    digitalWrite(LED, LOW);
    Serial.println("JOUR : LED ETEINTE");
  }
  else {
    digitalWrite(LED, HIGH);
    Serial.println("NUIT : LED ALLUMEE");
  }

  delay(500);
}