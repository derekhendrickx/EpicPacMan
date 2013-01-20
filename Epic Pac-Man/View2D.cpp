#include "View2D.h"


// Attibut qui retient l'instance de la classe (Pattern Singleton)
View *View2D::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
View2D::View2D() {
	model = Model::getInstance();
	dessin = new Dessin();
	ui = new UI();
	// D�finit la couleur � utiliser lors des appels � glClear(...)
	glClearColor(0.0,0.0,0.0,0);
}

/*
 * Destructeur
 */
View2D::~View2D() {
	delete dessin;
	delete ui;
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
View *View2D::getInstance() {
	if (View2D::instance == 0 )
		instance = new View2D();

	return instance;
}

/*
 * M�thode qui d�finis une premi�re Viewport contenant le jeu
 */
void View2D::viewportJeu() {
	yCoinInferieurGaucheViewportJeu = (float) h_global / 5;
	hauteurViewportJeu = (float) (4 * h_global) / 5;
	largeurViewportJeu = (float) (4 * w_global) / 5;

	delta1Jeu = model->getLabyrinthe()->getDelta1();
	delta2Jeu = model->getLabyrinthe()->getDelta2();

	// Taille et positionnement de la Viewport
	glViewport(0, yCoinInferieurGaucheViewportJeu, largeurViewportJeu, hauteurViewportJeu);
	glMatrixMode(GL_PROJECTION);
	// Initialisation de la matrice de projection
	glLoadIdentity();

	projectionViewportJeu();

	// D�sactivation de la profondeur
	glDisable(GL_DEPTH_TEST);
	// D�sactivetion de la lumi�re
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// Initialisation de la matrice de modelview
}

/*
 * M�thode qui d�finis une deuxi�me Viewport contenant les informations sur le jeu
 */
void View2D::viewportInfosJeu() {
	float h = (float) h_global / 5;
	float w = (float) (4 * w_global) / 5;
	double d1 = 1.0;
	double d2 = 1.0;
	double delta1 = 12.0;
	double delta2 = 5.0;

	// Taille et positionnement de la Viewport
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	// Initialisation de la matrice de projection
	glLoadIdentity();

	if ((w / h) > (delta1 / delta2)) {
		gluOrtho2D(d1, d1 + delta1 + ((w * delta2 / h) - delta1), d2, d2 + delta2);
	}
	if ((w / h) <= (delta1 / delta2)) {
		gluOrtho2D(d1, d1 + delta1, d2 - 0.5 * ((h * delta1 / w) - delta2), d2 + delta2 + 0.5 * ((h * delta1 / w) - delta2));
	}

	// D�sactivation de la profondeur
	glDisable(GL_DEPTH_TEST);

	// D�sactivetion de la lumi�re
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	// Initialisation de la matrice de modelview
	glLoadIdentity();
}

/*
 * M�thode qui d�finis une deuxi�me Viewport contenant les contr�les du jeu
 */
void View2D::viewportControles() {
	float x = (float) (4 * w_global) / 5;
	float w = (float) w_global / 5;
	d1Controles = -5.0;
	d2Controles = -20.0;
	delta1Controles = 10.0;
	delta2Controles = 40.0;

	// Taille et positionnement de la Viewport
	glViewport(x, 0, w, h_global);
	glMatrixMode(GL_PROJECTION);
	// Initialisation de la matrice de projection
	glLoadIdentity();

	if ((w / h_global) > (delta1Controles / delta2Controles)) {
		delta1Controles = delta1Controles + ((w * delta2Controles / h_global) - delta1Controles);
	}
	if ((w / h_global) <= (delta1Controles / delta2Controles)) {
		d2Controles =  d2Controles - 0.5 * ((h_global * delta1Controles / w) - delta2Controles);
		delta2Controles = delta2Controles + ((h_global * delta1Controles / w) - delta2Controles);
	}
	gluOrtho2D(d1Controles, d1Controles + delta1Controles, d2Controles, d2Controles + delta2Controles);

	// D�sactivation de la profondeur
	glDisable(GL_DEPTH_TEST);

	// D�sactivetion de la lumi�re
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	// Initialisation de la matrice de modelview
	glLoadIdentity();
}

/* 
 * M�thode qui d�finit le mod�le pour affichage � l'�cran
 */
void View2D::display(void) {
	// Initialisation du buffer de couleur � la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT);
	// Jeu
	viewportJeu();
	dessin->dessinerJeu2D();

	// Infos sur le jeu
	viewportInfosJeu();
	glColor3f(0,1,0);
	glPushMatrix();
		ui->affichageInfos();
	glPopMatrix();
	
	// Contr�les du jeu
	viewportControles();
	glColor3f(1,0,0);
	glPushMatrix();
		ui->dessinerBoutons();
	glPopMatrix();
	ui->dessinerFlechesDeControle();

	// Car on travaille en mode "double buffer", cf. main.cpp
	glutSwapBuffers();
}

/*
 * M�thode appel� en cas de redimensionnement de la fen�tre d'�cran
 */
void View2D::reshape(int w, int h) {	
	w_global=w;
	h_global=h;
}

/*
 * M�thode qui rafraichit l'affichage
 */
void View2D::redraw() {
	glutPostRedisplay();
}

/*
 * M�thode qui retourne un double repr�sentant le d1 de la viewport des contr�les
 */
double View2D::getD1Controles() {
	return d1Controles;
}

/*
 * M�thode qui retourne un double repr�sentant le d2 de la viewport des contr�les
 */
double View2D::getD2Controles() {
	return d2Controles;
}

/*
 * M�thode qui retourne un double repr�sentant le delta1 de la viewport des contr�les
 */
double View2D::getDelta1Controles() {
	return delta1Controles;
}

/*
 * M�thode qui retourne un double repr�sentant le delda2 de la viewport des contr�les
 */
double View2D::getDelta2Controles() {
	return delta2Controles;
}

/*
 * M�thode qui retourne un entier repr�sentant le w global
 */
int View2D::getWGlobal() {
	return w_global;
}

/*
 * M�thode qui retourne un entier repr�sentant le h global
 */
int View2D::getHGlobal() {
	return h_global;
}

/*
 * M�thode qui retourne un entier repr�sentant la coordonn�es 
 * Y du coin inf�rieur gauche de la viewport de jeu
 */
int View2D::getYCoinInferieurGaucheViewportJeu() {
	return yCoinInferieurGaucheViewportJeu;
}

/*
 * M�thode qui retourne un entier repr�sentant la largeur de la viewport de jeu
 */
int View2D::getLargeurViewportJeu() {
	return largeurViewportJeu;
}

/*
 * M�thode qui retourne un entier repr�sentant la hauteur de la viewport de jeu
 */
int View2D::getHauteurViewportJeu() {
	return hauteurViewportJeu;
}

/*
 * M�thode qui la projection de la viewport de jeu
 */
void View2D::projectionViewportJeu() {
	double d1 = model->getLabyrinthe()->getD1();
	double d2 = model->getLabyrinthe()->getD2();

	if ((largeurViewportJeu / hauteurViewportJeu) > (delta1Jeu / delta2Jeu)) {
		gluOrtho2D(d1 - 0.5 * ((largeurViewportJeu * delta2Jeu / hauteurViewportJeu) - delta1Jeu), d1 + delta1Jeu + 0.5 * ((largeurViewportJeu * delta2Jeu / hauteurViewportJeu) - delta1Jeu), d2, d2 + delta2Jeu);
	}
	if ((largeurViewportJeu / hauteurViewportJeu) <= (delta1Jeu / delta2Jeu)) {
		gluOrtho2D(d1, d1 + delta1Jeu, d2, d2 + delta2Jeu + ((hauteurViewportJeu * delta1Jeu / largeurViewportJeu) - delta2Jeu));
	}
}