#include "Texte.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Texte *Texte::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Texte::Texte() {
	model = model = Model::getInstance();
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
}

/*
 * Destructeur
 */
Texte::~Texte() {
	gluDeleteQuadric(quadric);
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
Texte *Texte::getInstance() {
	if (Texte::instance == 0 )
		instance = new Texte();

	return instance;
}

/*
 * Méthode qui convertis un entier récupéré par paramètre en pointeur de caractères
 */
char* Texte::convertirIntEnChar(int nb) {
	char *str = new char[TAILLE_STR];

	sprintf_s(str, TAILLE_STR, "%d", nb);

	return str;
}

/*
 * Méthode qui affiche le niveau de la partie
 */
void Texte::afficherNiveau() {
	char *niveau_str = convertirIntEnChar(model->getNiveau());
	char *titre = "Level : ";

	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(1.0, 3.25);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}

	for (char *p = niveau_str; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}

	free(niveau_str);
}

/*
 * Méthode qui affiche le score
 */
void Texte::afficherScore() {
	char *score_str = convertirIntEnChar(model->getScore());
	char *titre = "Score : ";

	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(5.0, 3.25);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}

	for (char *p = score_str; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}

	free(score_str);
}

/*
 * Méthode qui affiche les vies du Pac-Man
 */
void Texte::afficherVies() {
	glColor3f(1.0, 1.0, 0.0);

	glPushMatrix();
	glTranslated(11.0, 3.5, 0.0);

	int nbVies = model->getPacman()->getNbVies();
	for (int i(0); i < nbVies; i++) {
		glPushMatrix();
		glTranslated(i, 0.0, 0.0);
		gluPartialDisk(quadric, 0.0, 0.4, 30, 4, 140, 260);
		glPopMatrix();
	}
	glPopMatrix();
}

/*
 * Méthode qui affiche le mode du Pac-Man
 */
void Texte::afficherMode() {
	if (model->getPacman()->isSuper()) {
		char *titre = "INVINCIBLE";
		glColor3f(1.0, 0.0, 0.0);
		// Uniquement pour glutBitmapCharacter
		glRasterPos2f(17.0, 3.25);

		for (char *p = titre; *p != '\0'; p++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
		}
	}
}

/*
 * Méthode qui affiche Game Over si la partie est perdue
 */
void Texte::afficherFin() {
	char *titre = NULL;
	glColor3f(1.0, 0.0, 0.0);
	
	if (model->getPacman()->isGameOver()) {
		titre = "Game Over";
	} else if (model->getLabyrinthe()->getNbPastillesRestantes() == 0 && model->getNiveau() >= NB_NIVEAUX) {
		titre = "You won";
		//model->getPacman()->setNbVies(0);
	} else {
		titre = "";
	}

	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(24.0, 3.25);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}

}

/*
 * Méthode qui affiche le texte 2D
 */
void Texte::afficher2D() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "2D";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(-0.75, 7.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

/*
 * Méthode qui affiche le texte Parallère
 */
void Texte::afficherParallele() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "Parallele";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(-2.0, 5.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

/*
 * Méthode qui affiche le texte Perspective
 */
void Texte::afficherPerspective() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "Perspective";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(-3.0, 3.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

/*
 * Méthode qui affiche le texte Rejouer
 */
void Texte::afficherRejouer() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "Rejouer";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(-2.0, 1.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

/*
 * Méthode qui affiche le texte Quitter
 */
void Texte::afficherQuitter() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "Quitter";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(-1.85, -1.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

/*
 * Méthode qui affiche le caractère +
 */
void Texte::afficherPlus() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "+";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(-2.25, -3.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

/*
 * Méthode qui affiche le caractère -
 */
void Texte::afficherMoins() {
	glColor3f(1.0, 1.0, 1.0);

	char *titre = "-";
	// Uniquement pour glutBitmapCharacter
	glRasterPos2f(1.75, -3.0);

	for (char *p = titre; *p != '\0'; p++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}
