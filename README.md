# TrackChip
```
Ce projet a pour but de développer un traqueur autonome minimaliste,
capable de donner une position en extérieur comme en intérieur.
La position recueillie est ensuite envoyée sur notre site web,
accessible avec un navigateur internet.
L'objectif est d'avoir une précision de l'ordre de la dizaine de mètre.
```

## Device
Le device en lui-même est basé sur un micro-controleur ESP32, entouré des périphériques suivant :
* Altimètre
* GPS
* Module Sigfox
* Batterie

Le tout a été intégré dans un circuit imprimé grâce au logiciel KiCad.

## Cloud
Le site internet accède à la fois à la position de l'utilisateur et du tracker,
et calcule un itinéraire permettant de rejoindre le tracker.

Nous conservons également un historique des positions capable de recréer le trajet du device.
