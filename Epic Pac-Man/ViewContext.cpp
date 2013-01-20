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
 * M�thode qui retourne une vue repr�sentant la strat�gie en cours
 */
View *ViewContext::getStrategie()
{
	return strategie;
}

/*
 * M�thode qui initialise la strat�gie avec une vue pass�e en param�tre
 */
void ViewContext::setStrategie(View *view)
{
	strategie = view;
}
