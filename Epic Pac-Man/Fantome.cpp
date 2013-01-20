#include "Fantome.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Fantome *Fantome::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Fantome::Fantome() {
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	fantome = 0;
	init();
}

/*
 * Destructeur
 */
Fantome::~Fantome() {
	gluDeleteQuadric(quadric);
	glDeleteLists(fantome, 1);
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
Fantome *Fantome::getInstance() {
	if (Fantome::instance == 0 )
		instance = new Fantome();

	return instance;
}

/*
 * M�thode qui initialise la display list
 */
void Fantome::init() {
	fantome = glGenLists(1);

	glNewList(fantome, GL_COMPILE);
		fantome3D();
	glEndList();
}

/*
 * M�thode qui contient les intructions OpenGL pour la display list du fant�me en 3D
 */
void Fantome::fantome3D() {
	glutSolidSphere(TAILLE_PACMAN, 30, 10);
}

/*
 * M�thode qui dessine le Pac-Man en 2D
 */
void Fantome::dessinerFantome2D(FantomeModel *fantomeModel) {
	if (fantomeModel->isInvincible()) {
		// Un fant�me invincible est dessin� en rouge
		glColor3f(1.0, 0.0, 0.0);
	} else {
		// Un fant�me qui n'est pas invincible est dessin� en bleu
		glColor3f(0.0, 0.0, 1.0);
	}

	glPushMatrix();
		// D�placer le fant�me en (x, y)
		glTranslated(fantomeModel->getPositionX(), fantomeModel->getPositionY(), 0.0);
		glRectf(-0.3, -0.3, 0.3, 0.0);
		gluPartialDisk(quadric, 0.0, 0.3, 30, 4, 270, 180);
	glPopMatrix();
}

/*
 * M�thode qui dessine le Pac-Man en 2D
 */
void Fantome::dessinerFantome3D(FantomeModel *fantomeModel) {
	if (fantomeModel->isInvincible()) {
		// Un fant�me invincible est dessin� en orange
		glColor3f(1.0, 0.5, 0.0);
	} else {
		// Un fant�me qui n'est pas invincible est dessin� en bleu
		glColor3f(0.0, 0.0, 1.0);
	}

	glPushMatrix();
		// D�placer le fant�me en (x, y)
		glTranslated(fantomeModel->getPositionX(), fantomeModel->getPositionY(), 0.0);
		glCallList(fantome);
	glPopMatrix();
}
