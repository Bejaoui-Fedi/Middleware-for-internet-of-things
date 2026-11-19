# Projets IoT — ESP32, Wokwi et MQTT

Ce dépôt regroupe des ateliers pratiques autour de l’Internet des objets (IoT), développés avec des cartes ESP32. Les montages et leurs comportements peuvent être étudiés ou simulés avec [Wokwi](https://wokwi.com/). Les projets sont organisés en branches indépendantes afin de retrouver facilement le code, le câblage et les ressources propres à chaque expérimentation.

Les projets couvrent la connexion Wi-Fi, la lecture de capteurs, la commande d’actionneurs et la communication entre deux ESP32 par MQTT. Les branches des scénarios Publisher/Subscriber fournissent les deux programmes sous forme d’archives ZIP, accompagnés de captures et d’instructions.

## Catalogue des projets

| Projet | Description | Branche |
|---|---|---|
| [Connexion à un point d’accès Wi-Fi](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/connexion-point-acces) | Connexion de l’ESP32 au réseau `Wokwi-GUEST` et affichage de l’état de connexion et de l’adresse IP sur le moniteur série. | `connexion-point-acces` |
| [Détection de fuite de gaz](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/detection-fuite-gaz) | Mesure du niveau de gaz ; au-delà du seuil défini, une alerte sonore retentit et une LED clignote. | `detection-fuite-gaz` |
| [Station météo](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/station-meteo) | Mesure de la température et de l’humidité avec un DHT22, avec alerte sonore et lumineuse lorsque les conditions configurées sont atteintes. | `station-meteo` |
| [Système d’éclairage automatique](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/systeme-eclairage) | Détection de la luminosité par photorésistance et commande d’une LED selon la lumière ambiante. | `systeme-eclairage` |
| [Détection d’incendie](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/systeme-detection-incendie) | Détection d’une flamme et déclenchement d’une alerte par LED clignotante et buzzer. | `systeme-detection-incendie` |
| [Variation de l’angle d’un servomoteur](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/variation-angle-servomoteur) | Utilisation d’un potentiomètre pour régler l’angle d’un servomoteur de 0 à 180° ; l’angle est affiché sur le moniteur série. | `variation-angle-servomoteur` |
| [Scénario 1 — Alerte de proximité par ultrason](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/scenario-1-ultrason) | Un Publisher mesure la distance avec un HC-SR04 et publie les distances inférieures à 100 cm ; le Subscriber déclenche le buzzer et affiche l’alerte. | `scenario-1-ultrason` |
| [Scénario 2 — Alerte de température par DHT11](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/scenario-2-dht11) | Le Publisher envoie `1` lorsque la température dépasse 30 °C ; le Subscriber active le buzzer pour signaler l’alerte. | `scenario-2-dht11` |
| [Scénario 3 — Seuil de potentiomètre par MQTT](https://github.com/Bejaoui-Fedi/Middleware-for-internet-of-things/tree/scenario-3-potentiometre) | Le Publisher transmet la valeur du potentiomètre ; le Subscriber déclenche le buzzer si elle dépasse le seuil 250. | `scenario-3-potentiometre` |

## Organisation des branches

Chaque branche présente un projet autonome et son README. Les projets Wokwi contiennent leur sketch, leur schéma de câblage et une capture. Les trois scénarios MQTT comprennent également les archives `Publisher.zip` et `Subscriber.zip`, chacune avec les fichiers nécessaires à la simulation de sa carte ESP32.

Pour un scénario MQTT, ouvrez le README de sa branche, téléchargez les deux archives, puis importez chacune dans un projet Wokwi distinct. Les deux ESP32 doivent utiliser le même topic MQTT. Les exemples utilisent le réseau `Wokwi-GUEST` et le broker public `broker.hivemq.com` ; pour un déploiement réel, configurez votre réseau et un broker adapté.
