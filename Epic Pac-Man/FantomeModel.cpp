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
 * Méthode qui retourne de l'instance du modèle (Pattern Singleton) sous forme de pointeur
 */
FantomeModel *FantomeModel::getInstance() {
	if (instance == 0)
		instance = new FantomeModel();

	return instance;
}

/*
 * Renvoie true si le fantôme est invincible, false sinon
 */
bool FantomeModel::isInvincible() {
	return invincible;
}

/*
 * Méthode qui modifie le mode du fantôme (invincible ou vulnérable)
 */
void FantomeModel::setInvincible(bool isInvincible) {
	invincible = isInvincible;
}

/*
 * Méthode qui retourne la position x initiale du Fantôme
 */
double FantomeModel::getPositionXInitiale() {
	return positionXInitiale;
}

/*
 * Méthode qui retourne la position y initiale du Fantôme
 */
double FantomeModel::getPositionYInitiale() {
	return positionYInitiale;
}

/*
 * Méthode qui modifie la position x initiale du Fantôme en fonction d'un entier passé en paramètre
 */
void FantomeModel::setPositionXInitiale(double x) {
	positionXInitiale = x;
}

/*
 * Méthode qui modifie la position y initiale du Fantôme en fonction d'un entier passé en paramètre
 */
void FantomeModel::setPositionYInitiale(double y) {
	positionYInitiale = y;
}

/*
 * Méthode qui renvoie la position du Fantôme sur l'axe des X
 */
double FantomeModel::getPositionX() {
	return positionX;
}

/*
* Méthode qui renvoie la position du Fantôme sur l'axe des Y
*/
double FantomeModel::getPositionY() {
	return positionY;
}

/*
* Méthode qui modifie la position du Fantôme sur l'axe des X
* en fonction de la valeur passée en paramètre
*/
void FantomeModel::setPositionX(double x) {
	positionX = x;
}

/*
* Méthode qui modifie la position du Fantôme sur l'axe des Y
* en fonction de la valeur passée en paramètre
*/
void FantomeModel::setPositionY(double y) {
	positionY = y;
}

/*
 * Méthode qui renvoie l'orientation du fantome (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
 */
int FantomeModel::getOrientation() {
	return orientation;
}

/*
 * Méthode qui modifie l'orientation du Fantôme
 * en fonction de la valeur passée en paramètre
 */
void FantomeModel::setOrientation(int nouvelleOrientation) {
	orientation = nouvelleOrientation;
}
