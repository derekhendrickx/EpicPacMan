#include "Pastille.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Pastille *Pastille::instance = 0;

/*
 * Constructeur
 */
Pastille::Pastille(void)
{
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	pastille = 0;
	superPastille = 0;
	init();
}

/*
 * Destructeur
 */
Pastille::~Pastille(void)
{
	gluDeleteQuadric(quadric);
	glDeleteLists(pastille, 2);
}

/*
 * Méthode qui retourne l'instance du modèle (Pattern Singleton) sous forme de pointeur
 */
Pastille *Pastille::getInstance() {
	if (instance == 0)
		instance = new Pastille();

	return instance;
}

/*
 * Méthode qui initialise les displays lists
 */
void Pastille::init() {
	pastille = glGenLists(2);
	superPastille = pastille + 1;

	// Display list d'une pastille
	glNewList(pastille, GL_COMPILE);
		pastille3D();
	glEndList();

	// Display list d'une super pastille
	glNewList(superPastille, GL_COMPILE);
		superPastille3D();
	glEndList();
}

/*
 * Méthode qui contient les instructions OpenGL pour la display list d'une pastille en 3D
 */
void Pastille::pastille3D() {
	glutSolidSphere(TAILLE_PASTILLE, 30, 30);
}

/*
 * Méthode qui contient les instructions OpenGL pour la display list d'une super pastille en 3D
 */
void Pastille::superPastille3D() {
	glutSolidSphere(TAILLE_SUPER_PASTILLE, 30, 30);
}

/*
 * Méthode qui dessine une pastille en 2D
 */
void Pastille::dessinerPastille2D() {
	glColor3f(1.0, 1.0, 1.0);
	gluDisk(quadric, 0.0, TAILLE_PASTILLE, 30, 1);
}

/*
 * Méthode qui dessine une super pastille en 2D
 */
void Pastille::dessinerSuperPastille2D() {
	glColor3f(1.0, 0.0, 0.0);
	gluDisk(quadric, 0.0, TAILLE_SUPER_PASTILLE, 30, 2);
}

/*
 * Méthode qui dessine une pastille en 3D
 */
void Pastille::dessinerPastille3D() {
	glColor3f(1.0, 1.0, 1.0);
	glCallList(pastille);
}

/*
 * Méthode qui dessine une super pastille en 3D
 */
void Pastille::dessinerSuperPastille3D() {
	glColor3f(1.0, 0.0, 0.0);
	glCallList(superPastille);
}
