# Scénario 3 — Seuil de potentiomètre par MQTT

Deux cartes ESP32 communiquent par MQTT. Le Publisher lit la valeur d'un potentiomètre et la transmet au Subscriber. Celui-ci compare la valeur au seuil `250`, défini dans son code, puis active un buzzer et affiche une alerte sur le port série si la valeur est supérieure au seuil.

## Matériel et câblage

Deux ESP32, un potentiomètre raccordé au Publisher et un buzzer raccordé au Subscriber.

| Carte | Composant | Broche ESP32 |
|---|---|---|
| Publisher | Potentiomètre SIG | GPIO 34 |
| Subscriber | Buzzer | GPIO 5 |

Relier les bornes GND et VCC du potentiomètre respectivement à GND et 3,3 V de l'ESP32. Relier le buzzer selon le schéma Wokwi fourni dans l'archive Subscriber.

## Fonctionnement

1. Le Publisher lit la valeur analogique sur GPIO 34 et la publie sur `fedi/scenario3/valeur`.
2. Le Subscriber compare chaque valeur reçue au seuil `SEUIL` (250).
3. Si la valeur est supérieure à 250, le Subscriber affiche une alerte série et active le buzzer ; sinon, il arrête le buzzer et indique que la valeur est normale.

Les deux sketches utilisent le Wi-Fi `Wokwi-GUEST` et le broker MQTT public `broker.hivemq.com:1883`. Garder le même topic sur les deux cartes ; choisir un topic propre à votre installation pour éviter les messages partagés sur le broker public.

## Archives et captures

- [Télécharger le Publisher](Publisher.zip) — bibliothèque `PubSubClient`.
- [Télécharger le Subscriber](Subscriber.zip) — bibliothèque `PubSubClient`.
- [Ouvrir le Publisher dans Wokwi](https://wokwi.com/projects/481143519552073729).
- [Ouvrir le Subscriber dans Wokwi](https://wokwi.com/projects/481143544217734145).

### Publisher — potentiomètre

![Capture du Publisher avec le potentiomètre](images/publisher.png)

### Subscriber — buzzer et alerte série

![Capture du Subscriber avec le buzzer et l'alerte de seuil](images/subscriber.png)

Pour simuler, ouvrir les deux projets Wokwi, lancer chaque ESP32 et vérifier que les deux sketches utilisent le même topic MQTT.
