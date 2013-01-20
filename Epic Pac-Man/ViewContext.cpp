#include "ViewContext.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
ViewContext *ViewContext::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
ViewContext::ViewContext(void)
{
	strategie = NULL;
}

/*
 * Destructeur
 */
ViewContext::~ViewContext(void)
{
	// Vide car Singleton
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
ViewContext *ViewContext::getInstance() {
	if (ViewContext::instance == 0 )
		instance = new ViewContext();

	return instance;
}

/*
 * Méthode qui retourne une vue représentant la stratégie en cours
 */
View *ViewContext::getStrategie()
{
	return strategie;
}

/*
 * Méthode qui initialise la stratégie avec une vue passée en paramètre
 */
void ViewContext::setStrategie(View *view)
{
	strategie = view;
}
