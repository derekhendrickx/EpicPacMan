#include "PacMan.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
PacMan *PacMan::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
PacMan::PacMan(void)
{
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	pac = 0;
	init();
}

/*
 * Destructeur
 */
PacMan::~PacMan(void)
{
	gluDeleteQuadric(quadric);
	glDeleteLists(pac, 1);
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
PacMan *PacMan::getInstance() {
	if (PacMan::instance == 0 )
		instance = new PacMan();

	return instance;
}

/*
 * Méthode qui initialise la display list
 */
void PacMan::init() {
	pac = glGenLists(1);

	glNewList(pac, GL_COMPILE);
		pacman3D();
	glEndList();
}

/*
 * Méthode qui contient les instructions OpenGL pour la display list du Pac-Man en 3D
 */
void PacMan::pacman3D() {
	glutSolidSphere(TAILLE_PACMAN, 30, 30);
}

/*
 * Méthode qui dessine le Pac-Man en 2D
 */
void PacMan::dessinerPacman2D(PacManModel *pacman) {
	if (pacman->isSuper()) {
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glColor3f(1.0, 1.0, 0.0);
	}

	glPushMatrix();
		// Déplace le Pac-Man en (x, y)
		glTranslated(pacman->getPositionX(), pacman->getPositionY(), 0.0);

		// Dessine le Pac-Man en fonction de son orientation (gauche, droite, haut ou bas)
		switch (pacman->getOrientation()) {
			case LEFT:
				if (pacman->getEtat() == MOUTH_OPENED) {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 320, 260);
				} else {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 280, 340);
				}
				break;
			case RIGHT:
				if (pacman->getEtat() == MOUTH_OPENED) {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 140, 260);
				} else {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 100, 340);
				}
				break;
			case UP:
				if (pacman->getEtat() == MOUTH_OPENED) {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 50, 260);
				} else {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 10, 340);
				}
				break;
			case DOWN:
				if (pacman->getEtat() == MOUTH_OPENED) {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 230, 260);
				} else {
					gluPartialDisk(quadric, 0.0, TAILLE_PACMAN, 30, 4, 190, 340);
				}
				break;
		}
	glPopMatrix();
}

/*
 * Méthode qui dessine le Pac-Man en 3D
 */
void PacMan::dessinerPacman3D(PacManModel *pacman) {
	glPushMatrix();
		// Déplace le Pac-Man en (x, y)
		glTranslated(pacman->getPositionX(), pacman->getPositionY(), 0.0);
		glCallList(pac);
	glPopMatrix();
}
