#pragma once

#include <iostream>
#include <cmath>

#include "Utils.h"

#define NB_FANTOMES 3

class FantomeModel {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static FantomeModel *instance;
	// Position courante du Fant�me dans le labyrinthe
	double positionXInitiale, positionYInitiale;
	// Position courante du Fant�me dans le labyrinthe
	double positionX, positionY;
	// Indique si le fan�me peut �tre mang� par le pac-man (true) ou pas (false)
	bool invincible;
	// Retient l'orientation du fant�me
	int orientation;
	/*
	 * Constructeur (Pattern Singleton)
	 */
	FantomeModel();

public:
	/*
	 * M�thode qui retourne de l'instance du mod�le (Pattern Singleton) sous forme de pointeur
	 */
	static FantomeModel *getInstance();
	/*
	 * Renvoie true si le fant�me est invincible, false sinon
	 */
	bool isInvincible();
	/*
	 * M�thode qui modifie le mode du fant�me (invincible ou vuln�rable)
	 */
	void setInvincible(bool isInvincible);
	/*
	 * M�thode qui retourne la position x initiale du Fant�me
	 */
	double getPositionXInitiale();
	/*
	 * M�thode qui retourne la position y initiale du Fant�me
	 */
	double getPositionYInitiale();
	/*
	 * M�thode qui modifie la position x initiale du Fant�me en fonction d'un entier pass� en param�tre
	 */
	void setPositionXInitiale(double x);
	/*
	 * M�thode qui modifie la position y initiale du Fant�me en fonction d'un entier pass� en param�tre
	 */
	void setPositionYInitiale(double y);
	/*
	 * M�thode qui renvoie la position du Fant�me sur l'axe des X
	 */
	double getPositionX();
	/*
	 * M�thode qui renvoie la position du Fant�me sur l'axe des Y
	 */
	double getPositionY();
	/*
	 * M�thode qui modifie la position du Fant�me sur l'axe des X
	 * en fonction de la valeur pass�e en param�tre
	 */
	void setPositionX(double x);
	/*
	 * M�thode qui modifie la position du Fant�me sur l'axe des Y
	 * en fonction de la valeur pass�e en param�tre
	 */
	void setPositionY(double y);
	/*
	 * M�thode qui renvoie l'orientation du fantome (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
	 */
	int getOrientation();
	/*
	 * M�thode qui modifie l'orientation du Fant�me
	 * en fonction de la valeur pass�e en param�tre
	 */
	void setOrientation(int nouvelleOrientation);
};
