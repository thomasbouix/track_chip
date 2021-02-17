# TrackChip
Ce projet a pour but de développer un traqueur autonome minimaliste, capable de donner une position en extérieur comme en intérieur.
La position recueillie est ensuite envoyée sur notre site web, accessible via un navigateur internet.

```
L'objectif est d'avoir une précision de l'ordre de la dizaine de mètre.
```

## Device
Le device en lui-même est basé sur un micro-controleur ESP32, entouré des périphériques suivant :
* Altimètre
* GPS
* Module Sigfox
* Batterie
Le tout a été intégré dans un circuit imprimé grâce au logiciel KiCad.

```
Le device récupère la position avec le GPS quand il est dans un espace dégagé,
et en utilisant du scapping WiFi quand des réseaux sont disponibles.
```

## Cloud
Le site internet possède les fonctionnalitées suivantes :
* Position de l'utilisateur
* Position du traqueur
* Calcul de la différence d'altitude
* Calcul du trajet en voiture pour rejoindre le traqueur
* Historique des positions du traqueur
