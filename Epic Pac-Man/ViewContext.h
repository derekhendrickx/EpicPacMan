#pragma once

#include "Utils.h"

#include "View.h"

class ViewContext
{
private:
	// Attibut qui retient l'instance de la classe (Pattern Singleton)
	static ViewContext *instance;
	// Attribut qui retient une vue représentant la stratégie en cours
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
	 * Méthode qui retourne une vue représentant la stratégie en cours
	 */
	View *getStrategie();
	/*
	 * Méthode qui initialise la stratégie avec une vue passée en paramètre
	 */
	void setStrategie(View *view);
};

