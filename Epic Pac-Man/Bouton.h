#pragma once

#include "Utils.h"

class Bouton
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Bouton *instance;
	// Attribut pour les displays lists
	int type1, type2;
	/*
	 * Méthode qui initialise les displays lists
	 */
	void init();
	/*
	 * Constructeur (Pattern Singleton)
	 */
	Bouton(void);
public:
	/*
	 * Destructeur
	 */
	~Bouton(void);

	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static Bouton *getInstance();

	/*
	 * Méthode qui dessine un bouton en fonction d'un entier passé en paramètre représentant le type de bouton: 1 => grand et 2 => petit
	 */
	void dessinerBouton(int type);
};

