#pragma once

#include "Utils.h"

class Fleche
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Fleche *instance;
	// Attribut pour les displays lists
	int fleche, corps;
	/*
	 * M�thode qui initialise les displays lists
	 */
	void init();
	/*
	 * Constructeur
	 */
	Fleche(void);
public:
	/*
	 * Destructeur
	 */
	~Fleche(void);
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static Fleche *getInstance();
	/*
	 * M�thode qui dessine une fl�che pour les contr�les � la souris
	 */
	void dessinerFleche();
};

