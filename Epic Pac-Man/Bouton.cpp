#include "Bouton.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Bouton *Bouton::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Bouton::Bouton(void)
{
	type1 = 0;
	init();
}

/*
 * Destructeur (Pattern Singleton)
 */
Bouton::~Bouton(void)
{
	glDeleteLists(type1, 1);
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
Bouton *Bouton::getInstance() {
	if (Bouton::instance == 0 )
		instance = new Bouton();

	return instance;
}

/*
 * Méthode qui initialise la display list
 */
void Bouton::init() {
	type1 = glGenLists(2);
	type2 = type1 + 1;

	// Premier type de bouton: grand
	glNewList(type1, GL_COMPILE);
		glBegin(GL_QUADS);
			glVertex2d(-4.0, -1.5);
			glVertex2d(4.0, -1.5);
			glVertex2d(4.0, 1.5);
			glVertex2d(-4.0, 1.5);
		glEnd();
	glEndList();

	// Deuxième type de bouton: petit
	glNewList(type2, GL_COMPILE);
		glBegin(GL_QUADS);
			glVertex2d(-1.5, -1.5);
			glVertex2d(1.5, -1.5);
			glVertex2d(1.5, 1.5);
			glVertex2d(-1.5, 1.5);
		glEnd();
	glEndList();
}

/*
 * Méthode qui dessine un bouton en fonction d'un entier passé en paramètre représentant le type de bouton
 */
void Bouton::dessinerBouton(int type) {
	glColor3f(0.0, 0.0, 0.3);
	if (type == 1) {
		glCallList(type1);
	}
	else if (type == 2) {
		glCallList(type2);
	}
}
