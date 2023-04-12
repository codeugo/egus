# ![plot](./Pictures/egus48.png) 🦾 Bras robotisé contrôlable à l'aide d'un smartphone
MeArm 4502 contrôlable à l'aide du gyroscope d'un smartphone Android à destination des handicapés.
## Outils
**MeArm 4502  
Arduino Uno  
4*Servomoteur  
Câbles
Smartphone Android**
## Application Android
L'application à été construite à l'aide de MIT App Inventor.  
Son code est disponible sous le fichier [EgusApp.aia](https://github.com/codeugo/egus/blob/main/EgusApp.aia).
### Fonctions
*Bouge l'axe X et Y de la pince grace au gyroscope du téléphone;  
Permets d'ouvrir et fermer la pince à l'aide d'une commande vocal;  
Boutons permettant de changer précisément les valeurs des servomoteurs;*
## Code Arduino
Le code est disponible sous le fichier [EgusArduino.ino](https://github.com/codeugo/egus/blob/main/EgusArduino.ino).
### Pin Servomoteur et Bluetooth
Servomoteur milieu -> 11  
Servomoteur gauche -> 10  
Servomoteur droit -> 9  
Servomoteur pince -> 8  
Bluetooth -> TX et RX  
