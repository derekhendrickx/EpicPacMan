#include "FantomeModel.h"

// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
FantomeModel *FantomeModel::instance = 0;

FantomeModel::FantomeModel() {
	positionX = 0.0;
	positionY = 0.0;

	invincible = true;
	orientation = UP;
}

/*
 * M�thode qui retourne de l'instance du mod�le (Pattern Singleton) sous forme de pointeur
 */
FantomeModel *FantomeModel::getInstance() {
	if (instance == 0)
		instance = new FantomeModel();

	return instance;
}

/*
 * Renvoie true si le fant�me est invincible, false sinon
 */
bool FantomeModel::isInvincible() {
	return invincible;
}

/*
 * M�thode qui modifie le mode du fant�me (invincible ou vuln�rable)
 */
void FantomeModel::setInvincible(bool isInvincible) {
	invincible = isInvincible;
}

/*
 * M�thode qui retourne la position x initiale du Fant�me
 */
double FantomeModel::getPositionXInitiale() {
	return positionXInitiale;
}

/*
 * M�thode qui retourne la position y initiale du Fant�me
 */
double FantomeModel::getPositionYInitiale() {
	return positionYInitiale;
}

/*
 * M�thode qui modifie la position x initiale du Fant�me en fonction d'un entier pass� en param�tre
 */
void FantomeModel::setPositionXInitiale(double x) {
	positionXInitiale = x;
}

/*
 * M�thode qui modifie la position y initiale du Fant�me en fonction d'un entier pass� en param�tre
 */
void FantomeModel::setPositionYInitiale(double y) {
	positionYInitiale = y;
}

/*
 * M�thode qui renvoie la position du Fant�me sur l'axe des X
 */
double FantomeModel::getPositionX() {
	return positionX;
}

/*
* M�thode qui renvoie la position du Fant�me sur l'axe des Y
*/
double FantomeModel::getPositionY() {
	return positionY;
}

/*
* M�thode qui modifie la position du Fant�me sur l'axe des X
* en fonction de la valeur pass�e en param�tre
*/
void FantomeModel::setPositionX(double x) {
	positionX = x;
}

/*
* M�thode qui modifie la position du Fant�me sur l'axe des Y
* en fonction de la valeur pass�e en param�tre
*/
void FantomeModel::setPositionY(double y) {
	positionY = y;
}

/*
 * M�thode qui renvoie l'orientation du fantome (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
 */
int FantomeModel::getOrientation() {
	return orientation;
}

/*
 * M�thode qui modifie l'orientation du Fant�me
 * en fonction de la valeur pass�e en param�tre
 */
void FantomeModel::setOrientation(int nouvelleOrientation) {
	orientation = nouvelleOrientation;
}
