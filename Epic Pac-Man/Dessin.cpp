#include "Dessin.h"

/*
 * Constructeur (Pattern Singleton)
 */
Dessin::Dessin(void) {
	model = Model::getInstance();
	labyrinthe = model->getLabyrinthe();
	mur = Mur::getInstance();
	pastille = Pastille::getInstance();
	pacman = PacMan::getInstance();
	fantome = Fantome::getInstance();
	camera = Camera::getInstance();
}

/*
 * Destructeur
 */
Dessin::~Dessin(void) {
	// Vide car Pattern Singleton
}

/*
 * M�thode qui dessine le jeu en 2D
 */
void Dessin::dessinerJeu2D() {
	dessinerLabyrinthe2D();
	dessinerContenuLabyrinthe2D();
	dessinerPacman2D();
	dessinerFantome2D();
}

/*
 * M�thode qui dessine le labyrinthe en 2D
 */
void Dessin::dessinerLabyrinthe2D() {
	glColor3f(0.0, 0.0, 1.0);

	// Parcours du tableau contenant les murs
	for (int i(0); i < labyrinthe->getHauteurLabyrinthe(); i++) {
		glPushMatrix();

		if (i == 0) {
			glTranslated(0.0, 0.0, 0.0);
		}
		else {
			glTranslated(0.0, -i, 0.0);
		}
		for (int j(0); j < labyrinthe->getLargeurLabyrinthe(); j++) {
			glPushMatrix();
			glTranslated(j, 0.0, 0.0);

			// Dessine les murs du labyrinthe en fonction du contenu du tableau de pointeur
			switch (labyrinthe->getMur(i, j)) {
				case -1:
					break;
				case 0:
					break;
				case 1:
					mur->dessinerMurNord2D();
					break;
				case 2:
					glRotated(180, 0.0, 0.0, 1.0);
					mur->dessinerMurNord2D();
					break;
				case 3:
					glRotated(90, 0.0, 0.0, 1.0);
					mur->dessinerMurNord2D();
					break;
				case 4:
					glRotated(-90, 0.0, 0.0, 1.0);
					mur->dessinerMurNord2D();
					break;
				case 5:
					glRotated(-90, 0.0, 0.0, 1.0);
					mur->dessinerMurNordOuest2D();
					break;
				case 6:
					mur->dessinerMurNordOuest2D();
					break;
				case 7:
					glRotated(-180, 0.0, 0.0, 1.0);
					mur->dessinerMurNordOuest2D();
					break;
				case 8:
					glRotated(90, 0.0, 0.0, 1.0);
					mur->dessinerMurNordOuest2D();
					break;
				case 9:
					mur->dessinerMurEstOuest2D();
					break;
				case 10:
					glRotated(90, 0.0, 0.0, 1.0);
					mur->dessinerMurEstOuest2D();
					break;
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
}

/*
 * M�thode qui dessine les pastilles en 2D
 */
void Dessin::dessinerContenuLabyrinthe2D() {
	// Parcours du tableau contenant les pastilles
	for (int i(0); i < labyrinthe->getHauteurLabyrinthe(); i++) {
		glPushMatrix();

		if (i == 0) {
			glTranslated(0.0, 0.0, 0.0);
		}
		else {
			glTranslated(0.0, -i, 0.0);
		}
		for (int j(0); j < labyrinthe->getLargeurLabyrinthe(); j++) {
			glPushMatrix();
			glTranslated(j, 0.0, 0.0);

			switch (labyrinthe->getPastille(i, j)) {
				case 1:
					pastille->dessinerPastille2D();
					break;
				case 2:
					pastille->dessinerSuperPastille2D();
					break;
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
}

/*
 * M�thode qui dessine le Pac-Man en 2D
 */
void Dessin::dessinerPacman2D() {
	pacman->dessinerPacman2D(model->getPacman());
}

/*
 * M�thode qui dessine le Fant�me en 2D
 */
void Dessin::dessinerFantome2D() {
	fantome->dessinerFantome2D(model->getFantome());
}

/*
 * M�thode qui dessine le jeu en 3D
 */
void Dessin::dessinerJeu3D() {
	glPushMatrix();
		// Pour la rotation du plateau
		glTranslated(labyrinthe->getLargeurLabyrinthe()/2.0, -labyrinthe->getHauteurLabyrinthe()/2.0, 0.0);
		glRotated(camera->getAngleDeRotation(), 0.0, 0.0, 1.0);
		glTranslated(-labyrinthe->getLargeurLabyrinthe()/2.0, labyrinthe->getHauteurLabyrinthe()/2.0, 0.0);

		dessinerLabyrinthe3D();
		dessinerContenuLabyrinthe3D();
		dessinerPacman3D();
		dessinerFantome3D();
	glPopMatrix();
}

/*
 * M�thode qui dessine le labyrinthe en 3D
 */
void Dessin::dessinerLabyrinthe3D() {
	glEnable(GL_LIGHT2);

	// Position pour la lumi�re
    float position[4];
    position[0] = model->getPacman()->getPositionX();
    position[1] = model->getPacman()->getPositionY();
    position[2] = 4;
    position[3] = 1;

	// R�glage de la lumi�re
	glLightfv(GL_LIGHT2, GL_POSITION, position);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.7);
	
	// D�finition des mat�riaux pour la lumi�re: bleu
    glMaterialfv(GL_FRONT, GL_SPECULAR, Utils::SpecBleu);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Utils::DifBleu);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Utils::AmbBleu);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);

	for (int i(0); i < labyrinthe->getHauteurLabyrinthe(); i++) {
		glPushMatrix();

		if (i == 0) {
			glTranslated(0.0, 0.0, 0.0);
		}
		else {
			glTranslated(0.0, -i, 0.0);
		}
		for (int j(0); j < labyrinthe->getLargeurLabyrinthe(); j++) {
			glPushMatrix();
			glTranslated(j, 0.0, 0.0);

			// Dessine les murs du labyrinthe en fonction du contenu du tableau de pointeur
			switch (labyrinthe->getMur(i, j)) {
				case -1:
					break;
				case 0:
					break;
				case 1:
					mur->dessinerMurNord3D();
					break;
				case 2:
					glRotated(180, 1.0, 0.0, 0.0);
					mur->dessinerMurNord3D();
					break;
				case 3:
					glRotated(90, 0.0, 0.0, 1.0);
					mur->dessinerMurNord3D();
					break;
				case 4:
					glRotated(-90, 0.0, 0.0, 1.0);
					mur->dessinerMurNord3D();
					break;
				case 5:
					glRotated(-90, 0.0, 0.0, 1.0);
					mur->dessinerMurNordOuest3D();
					break;
				case 6:
					mur->dessinerMurNordOuest3D();
					break;
				case 7:
					glRotated(-180, 0.0, 0.0, 1.0);
					mur->dessinerMurNordOuest3D();
					break;
				case 8:
					glRotated(90, 0.0, 0.0, 1.0);
					mur->dessinerMurNordOuest3D();
					break;
				case 9:
					mur->dessinerMurEstOuest3D();
					break;
				case 10:
					glRotated(90, 0.0, 0.0, 1.0);
					mur->dessinerMurEstOuest3D();
					break;
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	glDisable(GL_LIGHT2);
}

/*
 * M�thode qui dessine les pastilles en 3D
 */
void Dessin::dessinerContenuLabyrinthe3D() {
	glEnable(GL_LIGHT1);

	for (int i(0); i < labyrinthe->getHauteurLabyrinthe(); i++) {
		glPushMatrix();

		if (i == 0) {
			glTranslated(0.0, 0.0, 0.0);
		}
		else {
			glTranslated(0.0, -i, 0.0);
		}
		for (int j(0); j < labyrinthe->getLargeurLabyrinthe(); j++) {
			glPushMatrix();
			glTranslated(j, 0.0, 0.0);

			switch (labyrinthe->getPastille(i, j)) {
				case 1:
					// D�finition des mat�riaux pour la lumi�re
					glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Utils::SpecBlanc);
					glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Utils::DifBlanc);
					glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Utils::AmbBlanc);

					pastille->dessinerPastille3D();
					break;
				case 2:
					// D�finition des mat�riaux pour la lumi�re
					glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Utils::SpecRouge);
					glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Utils::DifRouge);
					glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Utils::AmbRouge);

					pastille->dessinerSuperPastille3D();
					break;
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	glDisable(GL_LIGHT1);
}

/*
 * M�thode qui dessine le Pac-Man en 3D
 */
void Dessin::dessinerPacman3D() {
	glEnable(GL_LIGHT1);

	if (model->getPacman()->isSuper()) {
		// D�finition des mat�riaux pour la lumi�re: rouge
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Utils::SpecRouge);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Utils::DifRouge);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Utils::AmbRouge);
	}
	else {
		// D�finition des mat�riaux pour la lumi�re: jaune
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Utils::SpecJaune);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Utils::DifJaune);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Utils::AmbJaune);
	}

	pacman->dessinerPacman3D(model->getPacman());

	glDisable(GL_LIGHT1);
}

/*
 * M�thode qui dessine le Fant�me en 3D
 */
void Dessin::dessinerFantome3D() {
	glEnable(GL_LIGHT1);

	if (model->getPacman()->isSuper()) {
		// D�finition des mat�riaux pour la lumi�re: bleu
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Utils::SpecBleu);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Utils::DifBleu);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Utils::AmbBleu);
	}
	else {
		// D�finition des mat�riaux pour la lumi�re: rouge
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Utils::SpecRouge);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Utils::DifRouge);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Utils::AmbRouge);
	}

	fantome->dessinerFantome3D(model->getFantome());

	glDisable(GL_LIGHT1);
}
