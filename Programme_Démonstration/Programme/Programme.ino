/*
   "MODULE ARDUINO POUR VOITURE ÉLECTRIQUE" Pierron référence 33305
   Programme V1.0 : "Programme"
   Rédacteur : M. PAUL Pierre 2024
   Programme principal
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

// Fonction permettant de calculer la distance en centimetre (2 cm à 4 m) qui permettait un objet du capteur à ultrasons.
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
