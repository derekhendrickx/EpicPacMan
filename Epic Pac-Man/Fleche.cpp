#include "Fleche.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Fleche *Fleche::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Fleche::Fleche(void)
{
	fleche = 0;
	corps = 0;
	init();
}

/*
 * Destructeur (Pattern Singleton)
 */
Fleche::~Fleche(void)
{
	glDeleteLists(fleche, 2);
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
Fleche *Fleche::getInstance() {
	if (Fleche::instance == 0 )
		instance = new Fleche();

	return instance;
}

/*
 * M�thode qui initialise la display list
 */
void Fleche::init() {
	fleche = glGenLists(2);
	corps = fleche + 1;

	// Pointe de la fl�che
	glNewList(fleche, GL_COMPILE);
		glBegin(GL_TRIANGLES);
			glVertex2d(-1.0, 0.0);
			glVertex2d(1.0, 0.0);
			glVertex2d(0.0, 1.0);
		glEnd();
	glEndList();

	// Corps de la fl�che
	glNewList(corps, GL_COMPILE);
		glBegin(GL_QUADS);
			glVertex2d(-0.5, 0.0);
			glVertex2d(-0.5,-1.0);
			glVertex2d(0.5, -1.0);
			glVertex2d(0.5, 0.0);
		glEnd();
	glEndList();
}

/*
 * M�thode qui dessine une fl�che pour les contr�les � la souris
 */
void Fleche::dessinerFleche() {
	glColor3f(1.0, 1.0, 1.0);
	glCallList(fleche);
	glCallList(corps);
}