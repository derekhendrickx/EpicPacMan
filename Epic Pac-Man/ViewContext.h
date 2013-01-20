#pragma once

#include "Utils.h"

#include "View.h"

class ViewContext
{
private:
	// Attibut qui retient l'instance de la classe (Pattern Singleton)
	static ViewContext *instance;
	// Attribut qui retient une vue repr�sentant la strat�gie en cours
	View *strategie;
	/*
	 * Constructeur (Pattern Singleton)
	 */
	ViewContext(void);
public:
	/*
	 * Destructeur
	 */
	~ViewContext(void);
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static ViewContext *getInstance();
	/*
	 * M�thode qui retourne une vue repr�sentant la strat�gie en cours
	 */
	View *getStrategie();
	/*
	 * M�thode qui initialise la strat�gie avec une vue pass�e en param�tre
	 */
	void setStrategie(View *view);
};

