#pragma once

#include <iostream>
#include <cmath>

#include "Utils.h"

#define NB_FANTOMES 3

class FantomeModel {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static FantomeModel *instance;
	// Position courante du Fantôme dans le labyrinthe
	double positionXInitiale, positionYInitiale;
	// Position courante du Fantôme dans le labyrinthe
	double positionX, positionY;
	// Indique si le fanôme peut être mangé par le pac-man (true) ou pas (false)
	bool invincible;
	// Retient l'orientation du fantôme
	int orientation;
	/*
	 * Constructeur (Pattern Singleton)
	 */
	FantomeModel();

public:
	/*
	 * Méthode qui retourne de l'instance du modèle (Pattern Singleton) sous forme de pointeur
	 */
	static FantomeModel *getInstance();
	/*
	 * Renvoie true si le fantôme est invincible, false sinon
	 */
	bool isInvincible();
	/*
	 * Méthode qui modifie le mode du fantôme (invincible ou vulnérable)
	 */
	void setInvincible(bool isInvincible);
	/*
	 * Méthode qui retourne la position x initiale du Fantôme
	 */
	double getPositionXInitiale();
	/*
	 * Méthode qui retourne la position y initiale du Fantôme
	 */
	double getPositionYInitiale();
	/*
	 * Méthode qui modifie la position x initiale du Fantôme en fonction d'un entier passé en paramètre
	 */
	void setPositionXInitiale(double x);
	/*
	 * Méthode qui modifie la position y initiale du Fantôme en fonction d'un entier passé en paramètre
	 */
	void setPositionYInitiale(double y);
	/*
	 * Méthode qui renvoie la position du Fantôme sur l'axe des X
	 */
	double getPositionX();
	/*
	 * Méthode qui renvoie la position du Fantôme sur l'axe des Y
	 */
	double getPositionY();
	/*
	 * Méthode qui modifie la position du Fantôme sur l'axe des X
	 * en fonction de la valeur passée en paramètre
	 */
	void setPositionX(double x);
	/*
	 * Méthode qui modifie la position du Fantôme sur l'axe des Y
	 * en fonction de la valeur passée en paramètre
	 */
	void setPositionY(double y);
	/*
	 * Méthode qui renvoie l'orientation du fantome (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
	 */
	int getOrientation();
	/*
	 * Méthode qui modifie l'orientation du Fantôme
	 * en fonction de la valeur passée en paramètre
	 */
	void setOrientation(int nouvelleOrientation);
};
