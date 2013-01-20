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
 * Méthode qui retourne de l'instance du modèle (Pattern Singleton) sous forme de pointeur
 */
PacManModel *PacManModel::getInstance() {
	if (instance == 0)
		instance = new PacManModel();

	return instance;
}

/*
 * Méthode qui retourne la position x initiale du Pac-Man
 */
double PacManModel::getPositionXInitiale() {
	return positionXInitiale;
}

/*
 * Méthode qui retourne la position y initiale du Pac-Man
 */
double PacManModel::getPositionYInitiale() {
	return positionYInitiale;
}

/*
 * Méthode qui modifie la position x initiale du Pac-Man en fonction d'un entier passé en paramètre
 */
void PacManModel::setPositionXInitiale(double x) {
	positionXInitiale = x;
}

/*
 * Méthode qui modifie la position y initiale du Pac-Man en fonction d'un entier passé en paramètre
 */
void PacManModel::setPositionYInitiale(double y) {
	positionYInitiale = y;
}

/*
 * Méthode qui retourne la position x actuelle du Pac-Man
 */
double PacManModel::getPositionX() {
	return positionX;
}

/*
 * Méthode qui retourne la position y actuelle du Pac-Man
 */
double PacManModel::getPositionY() {
	return positionY;
}

/*
 * Méthode qui modifie la position x actuelle du Pac-Man en fonction d'un entier passé en paramètre
 */
void PacManModel::setPositionX(double x) {
	positionX = Utils::arrondiDeuxDecimale(x);
}

/*
 * Méthode qui modifie la position y actuelle du Pac-Man en fonction d'un entier passé en paramètre
 */
void PacManModel::setPositionY(double y) {
	positionY = Utils::arrondiDeuxDecimale(y);
}

/*
 * Méthode qui retourne l'orientation du Pac-Man
 */
int PacManModel::getOrientation() {
	return orientation;
}

/*
 * Méthode qui modifie l'orientation du Pac-Man en fonction 
 * de la nouvelle orientation passée en paramètre
 */
void PacManModel::setOrientation(int nouvelleOrientation) {
	orientation = nouvelleOrientation;
}

/*
 * Méthode qui retourne l'orientation suivante du Pac-Man
 */
int PacManModel::getOrientationSuivante() {
	return orientationSuivante;
}

/*
 * Méthode qui modifie l'orientation suivante du Pac-Man en fonction 
 * de la nouvelle orientation passée en paramètre
 */
void PacManModel::setOrientationSuivante(int nouvelleOrientationSuivante) {
	orientationSuivante = nouvelleOrientationSuivante;
}

/*
 * Méthode qui retourne l'état de la bouche du Pac-Man
 */
Etat PacManModel::getEtat() {
	return etat;
}

/*
 * Méthode qui modifie l'état de la bouche du Pac-Man en fonction 
 * du nouvel état passé en paramètre
 */
void PacManModel::setEtat(Etat nouvelEtat) {
	etat = nouvelEtat;
}

/*
 * Méthode qui retourne true si le Pac-Man est dans le mode super (invincible), false sinon
 */
bool PacManModel::isSuper() {
	return super;
}

/*
 * Méthode qui modifie le mode du Pac-Man en fonction d'un boolean passé en 
 * paramètre représentant le nouveau mode
 */
void PacManModel::setSuper(bool isSuper) {
	super = isSuper;
}

/*
 * Méthode qui retourne le nombre de vies restantes
 */
int PacManModel::getNbVies() {
	return nbVies;
}

/*
 * Méthode qui incrémente le nombre de vies restantes
 */
void PacManModel::incNbVies() {
	if (nbVies < 5) {
		nbVies++;
	}
}

/*
 * Méthode qui décrémente le nombre de vies restantes
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
 * Méthode qui modifie le nombre de vies du Pac-Man en fonction 
 * d'un nouveau nombre de vies passé en paramètre
 */
void PacManModel::setNbVies(int newNbVies) {
	if (newNbVies == 0) {
		gameOver = true;
	}

	nbVies = newNbVies;
}

/*
 * Méthode qui retourne true si la bouche du Pac-Man est animée, false sinon
 */
bool PacManModel::isMouthAnimated() {
	return mouthAnimated;
}

/*
 * Méthode qui modifie l'état de la bouche du Pac-Man en fonction d'un boolean 
 * passé en paramètre représentant le nouvel état
 */
void PacManModel::setMouthAnimated(bool animated) {
	mouthAnimated = animated;
}

/*
 * Méthode qui retourne true si la partie est perdue, false sinon
 */
bool PacManModel::isGameOver() {
	return gameOver;
}

/*
 * Méthode fait passer l'attribut gameOver à false pour indiquer
 * que la partie n'a pas été perdue
 */
void PacManModel::notGameOver() {
	gameOver = false;
}
