
#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password, 6);

  Serial.print("Connexion au WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnexion reussie !");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
