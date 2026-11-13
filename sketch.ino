#include <DHT.h>

#define DHT_PIN 4
#define LED 2
#define BUZZER 25

DHT dht(DHT_PIN, DHT22);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Erreur DHT22");
    delay(2000);
    return;
  }

  Serial.print("Temperature : ");
  Serial.println(temp);

  Serial.print("Humidite : ");
  Serial.println(hum);

  if (temp > 30 && hum < 40) {

    Serial.println("ARROSEZ VOS PLANTE");

    tone(BUZZER, 1000);
    delay(4000);
    noTone(BUZZER);

    for (int i = 0; i < 10; i++) {
      digitalWrite(LED, HIGH);
      delay(250);
      digitalWrite(LED, LOW);
      delay(250);
    }
  }

  delay(2000);
}
