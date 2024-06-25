# [33305](https://www.pierron.fr/module-arduinotm-pour-voiture-electrique.html)-Module_ARDUINO_pour_voiture_electrique

<p align='center' width="100%">
    <img width="50%" src="https://www.pierron.fr/media/catalog/product/cache/1/image/800x800/9df78eab33525d08d6e5fb8d27136e95/3/3/33305_-v2023_1.jpg">
</p>

<div align='justify'>

Ce module vient se connecter sous le châssis de la voiture électrique 33005.10. En y connectant un carte Arduino™ de type Nano, l’ensemble des composants électriques seront pilotables par ordinateur. Il sera alors possible de réaliser un programme qui, téléversé dans la carte, fera fonctionner la voiture tel que vous l’avez souhaité.

</div>

## Caractéristiques techniques :
- Compatible Arduino™ Nano
- Équipée d'un capteur ultrasons et d'un buzzer
- Dimensions (L x l x h) : 70 x 45 x 25 mm

## Environnement nécessaire :
- Une voiture électrique [33005](https://www.pierron.fr/voiture-electrique.html)

## Ressources à télécharger :

- Documentation : [Télécharger]()

- Arduino IDE : [Télécharger](https://www.arduino.cc/en/software)

- mBlock : [Télécharger](https://mblock.cc/pages/downloads)

## Programme de démonstration :

```cpp
/*
   "MODULE ARDUINO POUR VOITURE ÉLECTRIQUE" Pierron référence 33305
   Programme V1.0 : "Programme"
   Rédacteur : M. PAUL Pierre 2024
*/

// Déclarations des entrées et sorties.
#define AMPOULE_DROIT 2
#define AMPOULE_GAUCHE 12
#define DEL 13
#define BOUTON_POUSSOIR 3
#define POTEMTIOMETRE A7
#define BUZZER 11
#define PHOTODIODE A4
#define INTERRUPTEUR_DROIT 10
#define INTERRUPTEUR_GAUCHE A3
#define ULTRASONS_TRIG A5
#define ULTRASONS_ECHO A0
#define VITESSE_MOTEUR_GAUCHE 9
#define VITESSE_MOTEUR_DROIT 6
#define MOTEUR_DROIT_AVANT 4
#define MOTEUR_DROIT_ARRIERE 5
#define MOTEUR_GAUCHE_AVANT 7
#define MOTEUR_GAUCHE_ARRIERE 8

void setup() {
  // Définition de la vitesse de communication de la liaison USB.
  Serial.begin(115200);
  delay(1000);
  // Définition des entées et des sorties de la carte Arduino NANO.
  pinMode(AMPOULE_DROIT, OUTPUT);
  pinMode(AMPOULE_GAUCHE, OUTPUT);
  pinMode(DEL, OUTPUT);
  pinMode(BOUTON_POUSSOIR, INPUT);
  pinMode(POTEMTIOMETRE, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PHOTODIODE, INPUT);
  pinMode(INTERRUPTEUR_DROIT, INPUT);
  pinMode(INTERRUPTEUR_GAUCHE, INPUT);
  pinMode(ULTRASONS_TRIG, OUTPUT);
  pinMode(ULTRASONS_ECHO, INPUT);
  pinMode(VITESSE_MOTEUR_GAUCHE, OUTPUT);
  pinMode(VITESSE_MOTEUR_DROIT, OUTPUT);
  pinMode(MOTEUR_DROIT_AVANT, OUTPUT);
  pinMode(MOTEUR_DROIT_ARRIERE, OUTPUT);
  pinMode(MOTEUR_GAUCHE_AVANT, OUTPUT);
  pinMode(MOTEUR_GAUCHE_ARRIERE, OUTPUT);
}

void loop() {

}

// Fonction permettant de faire avancer la voiture électrique (iPWM -> 0 à 255).
void Avancer(int iPWM) {
  analogWrite(VITESSE_MOTEUR_GAUCHE, iPWM);
  analogWrite(VITESSE_MOTEUR_DROIT, iPWM);
  digitalWrite(MOTEUR_DROIT_AVANT, HIGH);
  digitalWrite(MOTEUR_DROIT_ARRIERE, LOW);
  digitalWrite(MOTEUR_GAUCHE_AVANT, HIGH);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, LOW);
}

// Fonction permettant de faire reculer la voiture électrique (iPWM -> 0 à 255).
void Reculer(int iPWM) {
  analogWrite(VITESSE_MOTEUR_GAUCHE, iPWM);
  analogWrite(VITESSE_MOTEUR_DROIT, iPWM);
  digitalWrite(MOTEUR_DROIT_AVANT, LOW);
  digitalWrite(MOTEUR_DROIT_ARRIERE, HIGH);
  digitalWrite(MOTEUR_GAUCHE_AVANT, LOW);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, HIGH);
}

// Fonction permettant de faire tourner à droite la voiture électrique (iPWM -> 0 à 255).
void Tourner_Droite(int iPWM) {
  analogWrite(VITESSE_MOTEUR_GAUCHE, 0);
  analogWrite(VITESSE_MOTEUR_DROIT, iPWM);
  digitalWrite(MOTEUR_DROIT_AVANT, HIGH);
  digitalWrite(MOTEUR_DROIT_ARRIERE, LOW);
  digitalWrite(MOTEUR_GAUCHE_AVANT, LOW);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, LOW);
}

// Fonction permettant de faire tourner à gauche la voiture électrique (iPWM -> 0 à 255).
void Tourner_Gauche(int iPWM) {
  analogWrite(VITESSE_MOTEUR_GAUCHE, iPWM);
  analogWrite(VITESSE_MOTEUR_DROIT, 0);
  digitalWrite(MOTEUR_DROIT_AVANT, LOW);
  digitalWrite(MOTEUR_DROIT_ARRIERE, LOW);
  digitalWrite(MOTEUR_GAUCHE_AVANT, HIGH);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, LOW);
}

// Fonction permettant de lire l'état logique du bouton poussoir (0 ou 1).
int Lecture_Bouton_Poussoir(void) {
  return digitalRead(BOUTON_POUSSOIR);
}

// Fonction permettant de lire l'état logique de l'interrupteur droit (0 ou 1).
int Lecture_Interrupteur_Droit(void) {
  return digitalRead(INTERRUPTEUR_DROIT);
}

// Fonction permettant de lire l'état logique de l'interrupteur gauche (0 ou 1).
int Lecture_Interrupteur_Gauche(void) {
  return digitalRead(INTERRUPTEUR_GAUCHE);
}

// Fonction permettant d'allumer ou d'éteindre l'ampoule droite (0 ou 1).
void Allumer_Eteindre_Ampoule_Droit(bool bEtat) {
  if (bEtat == 1) {
    digitalWrite(AMPOULE_DROIT, HIGH);
  } else {
    digitalWrite(AMPOULE_DROIT, LOW);
  }
}

// Fonction permettant d'allumer ou d'éteindre l'ampoule gauche (0 ou 1).
void Allumer_Eteindre_Ampoule_Gauche(bool bEtat) {
  if (bEtat == 1) {
    digitalWrite(AMPOULE_GAUCHE, HIGH);
  } else {
    digitalWrite(AMPOULE_GAUCHE, LOW);
  }
}

// Fonction permettant d'allumer ou d'éteindre la diode électroluminescente (0 ou 1).
void Allumer_Eteindre_DEL(bool bEtat) {
  if (bEtat == 1) {
    digitalWrite(DEL, HIGH);
  } else {
    digitalWrite(DEL, LOW);
  }
}

// Fonction permettant de calculer la tension du potentiomètre.
float Lecture_Potentiometre(void) {
  float fMesure = 0;
  fMesure = analogRead(POTEMTIOMETRE);
  return (fMesure * (3.3 / 1023));
}

// Fonction permettant de calculer la tension de la photodiode.
float Lecture_Photodiode(void) {
  float fMesure = 0;
  fMesure = analogRead(PHOTODIODE);
  return (fMesure * (3.3 / 1023));
}

// Fonction permettant de calculer la distance en centimetre (2cm à 4m) qui permettait un objet du capteur à ultrasons.
int Lecture_Distance(void) {
  long lMesure = 0;
  digitalWrite(ULTRASONS_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONS_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONS_TRIG, LOW);
  lMesure = pulseIn(ULTRASONS_ECHO, HIGH);
  delay(25);
  return (lMesure * (0.034 / 2));
}

// Fonction permettant d'émettre un son.
void Buzzer(int iFrequence, long lDuree){
  tone(BUZZER, iFrequence, lDuree);
}
```

#### À propos :
<div align='center'>

© [PIERRON - ASCO & CELDA](https://www.pierron.fr) 2024 - 62 rue de Siltzheim - 57200 RÉMELFING - France

</div>
