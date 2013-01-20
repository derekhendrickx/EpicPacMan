#include "PacManModel.h"

// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
PacManModel *PacManModel::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
PacManModel::PacManModel() {
	positionX = 0.0;
	positionY = 0.0;
	super = false;
	orientation = LEFT;
	orientationSuivante = LEFT;
	etat = MOUTH_OPENED;
	nbVies = 3;
	mouthAnimated = true;
	gameOver = false;
}

/*
 * Destructeur
 */
PacManModel::~PacManModel() {
	// Vide car Pattern Singleton
}

/*
 * M�thode qui retourne de l'instance du mod�le (Pattern Singleton) sous forme de pointeur
 */
PacManModel *PacManModel::getInstance() {
	if (instance == 0)
		instance = new PacManModel();

	return instance;
}

/*
 * M�thode qui retourne la position x initiale du Pac-Man
 */
double PacManModel::getPositionXInitiale() {
	return positionXInitiale;
}

/*
 * M�thode qui retourne la position y initiale du Pac-Man
 */
double PacManModel::getPositionYInitiale() {
	return positionYInitiale;
}

/*
 * M�thode qui modifie la position x initiale du Pac-Man en fonction d'un entier pass� en param�tre
 */
void PacManModel::setPositionXInitiale(double x) {
	positionXInitiale = x;
}

/*
 * M�thode qui modifie la position y initiale du Pac-Man en fonction d'un entier pass� en param�tre
 */
void PacManModel::setPositionYInitiale(double y) {
	positionYInitiale = y;
}

/*
 * M�thode qui retourne la position x actuelle du Pac-Man
 */
double PacManModel::getPositionX() {
	return positionX;
}

/*
 * M�thode qui retourne la position y actuelle du Pac-Man
 */
double PacManModel::getPositionY() {
	return positionY;
}

/*
 * M�thode qui modifie la position x actuelle du Pac-Man en fonction d'un entier pass� en param�tre
 */
void PacManModel::setPositionX(double x) {
	positionX = Utils::arrondiDeuxDecimale(x);
}

/*
 * M�thode qui modifie la position y actuelle du Pac-Man en fonction d'un entier pass� en param�tre
 */
void PacManModel::setPositionY(double y) {
	positionY = Utils::arrondiDeuxDecimale(y);
}

/*
 * M�thode qui retourne l'orientation du Pac-Man
 */
int PacManModel::getOrientation() {
	return orientation;
}

/*
 * M�thode qui modifie l'orientation du Pac-Man en fonction 
 * de la nouvelle orientation pass�e en param�tre
 */
void PacManModel::setOrientation(int nouvelleOrientation) {
	orientation = nouvelleOrientation;
}

/*
 * M�thode qui retourne l'orientation suivante du Pac-Man
 */
int PacManModel::getOrientationSuivante() {
	return orientationSuivante;
}

/*
 * M�thode qui modifie l'orientation suivante du Pac-Man en fonction 
 * de la nouvelle orientation pass�e en param�tre
 */
void PacManModel::setOrientationSuivante(int nouvelleOrientationSuivante) {
	orientationSuivante = nouvelleOrientationSuivante;
}

/*
 * M�thode qui retourne l'�tat de la bouche du Pac-Man
 */
Etat PacManModel::getEtat() {
	return etat;
}

/*
 * M�thode qui modifie l'�tat de la bouche du Pac-Man en fonction 
 * du nouvel �tat pass� en param�tre
 */
void PacManModel::setEtat(Etat nouvelEtat) {
	etat = nouvelEtat;
}

/*
 * M�thode qui retourne true si le Pac-Man est dans le mode super (invincible), false sinon
 */
bool PacManModel::isSuper() {
	return super;
}

/*
 * M�thode qui modifie le mode du Pac-Man en fonction d'un boolean pass� en 
 * param�tre repr�sentant le nouveau mode
 */
void PacManModel::setSuper(bool isSuper) {
	super = isSuper;
}

/*
 * M�thode qui retourne le nombre de vies restantes
 */
int PacManModel::getNbVies() {
	return nbVies;
}

/*
 * M�thode qui incr�mente le nombre de vies restantes
 */
void PacManModel::incNbVies() {
	if (nbVies < 5) {
		nbVies++;
	}
}

/*
 * M�thode qui d�cr�mente le nombre de vies restantes
 */
void PacManModel::decNbVies() {
	if (nbVies > 0) {
		nbVies--;
	}
	if (nbVies == 0) {
		gameOver = true;
	}
}

/*
 * M�thode qui modifie le nombre de vies du Pac-Man en fonction 
 * d'un nouveau nombre de vies pass� en param�tre
 */
void PacManModel::setNbVies(int newNbVies) {
	if (newNbVies == 0) {
		gameOver = true;
	}

	nbVies = newNbVies;
}

/*
 * M�thode qui retourne true si la bouche du Pac-Man est anim�e, false sinon
 */
bool PacManModel::isMouthAnimated() {
	return mouthAnimated;
}

/*
 * M�thode qui modifie l'�tat de la bouche du Pac-Man en fonction d'un boolean 
 * pass� en param�tre repr�sentant le nouvel �tat
 */
void PacManModel::setMouthAnimated(bool animated) {
	mouthAnimated = animated;
}

/*
 * M�thode qui retourne true si la partie est perdue, false sinon
 */
bool PacManModel::isGameOver() {
	return gameOver;
}

/*
 * M�thode fait passer l'attribut gameOver � false pour indiquer
 * que la partie n'a pas �t� perdue
 */
void PacManModel::notGameOver() {
	gameOver = false;
}
