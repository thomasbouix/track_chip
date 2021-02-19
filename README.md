# TrackChip, le traqueur autonome ! 
L'objectif de ce projet est triple :
* Développer un traqueur minimaliste et autonome
* Obtenir une position en extérieur et en intérieur
* Avoir une précision de l'ordre de la dizaine de mètre

## Device
Le device en lui-même est basé sur un micro-controleur ESP32, entouré des périphériques suivant :
* Altimètre BMP180
* GPS ADA746
* Module Sigfox BRKWS01
* Batterie LIPO 1050mAh

Le tout a été intégré dans un circuit imprimé.

## Site Web
Le site internet possède les fonctionnalitées suivantes :
* Position de l'utilisateur
* Position du traqueur
* Calcul de la différence d'altitude
* Calcul du trajet en voiture pour rejoindre le traqueur
* Historique des positions du traqueur


# Notice d'utilisation
Le système dans son ensemble possède le comportement suivant :
* Le device utilise le GPS quand il reçoit un signal
* Le device utilise le scrapping WiFi quand le GPS est indisponible
* La position est envoyée sur notre serveur via le réseau SigFox
* Les informations sont accessibles sur notre site via un client Web. 

## Device
Le device s'allume et s'éteint avec le boutton ON/OFF sur le côté de sa boîte protectrice.
Il envoie alors sa position toutes les 5 minutes.
Le batterie du device est rechargeable en dévissant la boite par cable micro-USB.

## Réseau SigFox
Le device envoie ses données sur un backend web en utilisant le réseau SigFox.
Ce backend redirigie ensuite ces informations sur notre serveur grâce à une fonction de callback.
On accède au backend via l'URL suivant :
```
https://backend.sigfox.com/auth/login
```

## Site Web
Le site web est disponible à l'adresse suivante :
```
https://track-chip.alwaysdata.net/
```

