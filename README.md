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
#define AMPOULE_DROIT 4
#define AMPOULE_GAUCHE 2
#define DEL 3
#define BOUTON_POUSSOIR A2
#define POTEMTIOMETRE A0
#define BUZZER 13
#define PHOTODIODE A1
#define INTERRUPTEUR_DROIT A3
#define INTERRUPTEUR_GAUCHE A4
#define ULTRASONS_TRIG 10
#define ULTRASONS_ECHO 9
#define VITESSE_MOTEUR_GAUCHE 5
#define VITESSE_MOTEUR_DROIT 6
#define MOTEUR_DROIT_AVANT 7
#define MOTEUR_DROIT_ARRIERE 8
#define MOTEUR_GAUCHE_AVANT 11
#define MOTEUR_GAUCHE_ARRIERE 12

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
  /* À compléter en fonction des besoins par l'appel d'une ou plusieurs fonctions ci-dessous. */
  /* -> [valeur retournée ou non] nom de la fonction (argument(s) ou non) {} */
}

// Fonction permettant de faire avancer la voiture électrique (iPuissance -> 0 à 100%).
void Avancer(int iPuissance) {
  int iPWM = map(iPuissance, 0, 100, 0, 255);
  analogWrite(VITESSE_MOTEUR_GAUCHE, iPWM);
  analogWrite(VITESSE_MOTEUR_DROIT, iPWM);
  digitalWrite(MOTEUR_DROIT_AVANT, HIGH);
  digitalWrite(MOTEUR_DROIT_ARRIERE, LOW);
  digitalWrite(MOTEUR_GAUCHE_AVANT, HIGH);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, LOW);
}

// Fonction permettant de faire reculer la voiture électrique (iPuissance -> 0 à 100%).
void Reculer(int iPuissance) {
  int iPWM = map(iPuissance, 0, 100, 0, 255);
  analogWrite(VITESSE_MOTEUR_GAUCHE, iPWM);
  analogWrite(VITESSE_MOTEUR_DROIT, iPWM);
  digitalWrite(MOTEUR_DROIT_AVANT, LOW);
  digitalWrite(MOTEUR_DROIT_ARRIERE, HIGH);
  digitalWrite(MOTEUR_GAUCHE_AVANT, LOW);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, HIGH);
}

// Fonction permettant de faire tourner à droite la voiture électrique (iPuissance -> 0 à 100%).
void Tourner_Droite(int iPuissance) {
  int iPWM = map(iPuissance, 0, 100, 0, 255);
  analogWrite(VITESSE_MOTEUR_GAUCHE, 0);
  analogWrite(VITESSE_MOTEUR_DROIT, iPWM);
  digitalWrite(MOTEUR_DROIT_AVANT, HIGH);
  digitalWrite(MOTEUR_DROIT_ARRIERE, LOW);
  digitalWrite(MOTEUR_GAUCHE_AVANT, LOW);
  digitalWrite(MOTEUR_GAUCHE_ARRIERE, LOW);
}

// Fonction permettant de faire tourner à gauche la voiture électrique (iPuissance -> 0 à 100%).
void Tourner_Gauche(int iPuissance) {
  int iPWM = map(iPuissance, 0, 100, 0, 255);
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

// Fonction permettant de contrôler l'éclairage de la diode électroluminescente (iLuminosite -> 0 à 100%).
void Allumer_Eteindre_DEL(int iLuminosite) {
  int iPWM = map(iLuminosite, 0, 100, 0, 255);
  analogWrite(DEL, iPWM);
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
void Buzzer(int iFrequence, long lDuree) {
  tone(BUZZER, iFrequence, lDuree);
}
```

#### À propos :
<div align='center'>

© [PIERRON - ASCO & CELDA](https://www.pierron.fr) 2024 - 62 rue de Siltzheim - 57200 RÉMELFING - France

</div>
