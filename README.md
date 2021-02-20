# TrackChip, le traqueur autonome ! 
L'objectif de ce projet est double :
* Développer un traqueur autonome de précision ~10m (partie Device)
* Récupérer ces informations sur un client WEB (partie Cloud)

### Device
Le device en lui-même est basé sur un micro-controleur ESP32, entouré des périphériques suivant :
* Altimètre BMP180
* GPS ADA746
* Module Sigfox BRKWS01
* Batterie LIPO 1050mAh
* Régulateur de tension 5V Polulu U1V11F5

```
Les sources des bibliothèques des périphériques ainsi que du PCB sont disponibles dans le dossier /devices du git.
```
### Site Web
Le site internet possède les fonctionnalitées suivantes :
* Position de l'utilisateur
* Position du traqueur
* Calcul de la différence d'altitude
* Calcul du trajet en voiture pour rejoindre le traqueur
* Historique des positions du traqueur

```
Les sources du serveur, de la base de donnée et du site Web sont disponibles dans la partie cloud/ du git.
```

# Notice d'utilisation
Le système dans son ensemble possède le comportement suivant :
* Le device utilise le GPS quand il reçoit un signal
* Le device utilise le scrapping WiFi quand le GPS est indisponible
* La position est envoyée sur notre serveur via le réseau SigFox
* Les informations sont accessibles sur notre site via un client Web. 

### Device
Le device s'allume et s'éteint avec le boutton ON/OFF sur le côté de sa boîte protectrice.
Il envoie alors sa position toutes les 5 minutes.

### Réseau SigFox
Le device envoie ses données sur un backend web en utilisant le réseau SigFox.
Ce backend redirigie ensuite ces informations sur notre serveur grâce à une fonction de callback.
On accède au backend via l'URL suivant :
```
https://backend.sigfox.com/auth/login
```

### Serveur
Le serveur est un ensemble de programmes gérant le site Web ainsi que la base de donnée. 
Il peut être hebergé sur une machine locale, ou bien sur internet via un VPS. 

### Site Web
Le site web est disponible à l'adresse suivante :
```
https://track-chip.alwaysdata.net/
```
Des identifiants seront demandés pour s'y connecter.
Contacter l'adminitrateur pour en obtenir.


