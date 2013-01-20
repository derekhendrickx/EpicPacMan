#include "View3D.h"


// Attibut qui retient l'instance de la classe (Pattern Singleton)
View *View3D::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
View3D::View3D() {
	camera = Camera::getInstance();
	model = Model::getInstance();
	dessin = new Dessin();
	ui = new UI();
	// Définit la couleur à utiliser lors des appels à glClear(...)
	glClearColor(0.0,0.0,0.0,0);
}

/*
 * Destructeur
 */
View3D::~View3D() {
	delete dessin;
	delete ui;
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
View *View3D::getInstance() {
	if (View3D::instance == 0 )
		instance = new View3D();

	return instance;
}

/*
 * Méthode qui définis une première Viewport contenant le jeu
 */
void View3D::viewportJeu() {
	yCoinInferieurGaucheViewportJeu = (float)  h_global / 5;
	hauteurViewportJeu = (float)  (4 * h_global) / 5;
	largeurViewportJeu = (float)  (4 * w_global) / 5;

	delta1Jeu = model->getLabyrinthe()->getDelta1();
	delta2Jeu = model->getLabyrinthe()->getDelta2();
	
	double cameraX = (model->getLabyrinthe()->getLargeurLabyrinthe() - 1) / 2;
	double cameraY = (model->getLabyrinthe()->getHauteurLabyrinthe() - 1) / 2;

	// Taille et positionnement de la Viewport
	glViewport(0, yCoinInferieurGaucheViewportJeu, largeurViewportJeu, hauteurViewportJeu);
	glMatrixMode(GL_PROJECTION);
	// Initialisation de la matrice de projection
	glLoadIdentity();

	projectionViewportJeu();

	// Activation de la profondeur
	glEnable(GL_DEPTH_TEST);

	// Lumière positionnelle ambiante et diffuse
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Utils::LightDifBlanc);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Utils::LightSpecBlanc);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Utils::LightAmbBlanc);
	glLightfv(GL_LIGHT0, GL_POSITION, Utils::Light1Pos);

	// Lumière positionnelle ambiante et diffuse
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Utils::LightDifBlanc);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Utils::LightSpecBlanc);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Utils::LightAmbBlanc);
	glLightfv(GL_LIGHT1, GL_POSITION, Utils::Light2Pos);

	// Spot
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Utils::LightDifBlanc);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Utils::LightSpecBlanc);
	glLightfv(GL_LIGHT2, GL_AMBIENT, Utils::LightAmbBlanc);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Utils::Spot1Dir);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 15);

	// Activation des lumières
	glEnable(GL_LIGHTING);

	// Activation de la normalisation des vecteurs normaux
    glEnable(GL_NORMALIZE);

	// Sélection du modèle d'ombre smooth
    glShadeModel(GL_SMOOTH);

	// Désactivation du culling
	glDisable(GL_CULL_FACE);

	// Camera
	gluLookAt(cameraX, -cameraY, 5, cameraX, -cameraY, 0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// Initialisation de la matrice de modelview
}

/*
 * Méthode qui définis une deuxième Viewport contenant les informations sur le jeu
 */
void View3D::viewportInfosJeu() {
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

	// Désactivation de la profondeur
	glDisable(GL_DEPTH_TEST);

	// Désactivetion de la lumière
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	// Initialisation de la matrice de modelview
	glLoadIdentity();
}

/*
 * Méthode qui définis une deuxième Viewport contenant les contrôles du jeu
 */
void View3D::viewportControles() {
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

	// Désactivation de la profondeur
	glDisable(GL_DEPTH_TEST);

	// Désactivetion de la lumière
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	// Initialisation de la matrice de modelview
	glLoadIdentity();
}

/* 
 * Méthode qui définit le modèle pour affichage à l'écran
 */
void View3D::display(void) {
	// Initialisation du buffer de couleur à la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Jeu
	viewportJeu();
	dessin->dessinerJeu3D();

	// Infos sur le jeu
	viewportInfosJeu();
	glColor3f(0,1,0);
	glPushMatrix();
		ui->affichageInfos();
	glPopMatrix();
	
	// Contrôles du jeu
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
 * Méthode appelé en cas de redimensionnement de la fenêtre d'écran
 */
void View3D::reshape(int w, int h) {	
	w_global=w;
	h_global=h;
}

/*
 * Méthode qui rafraichit l'affichage
 */
void View3D::redraw() {
	glutPostRedisplay();
}

/*
 * Méthode qui retourne un double représentant le d1 de la viewport des contrôles
 */
double View3D::getD1Controles() {
	return d1Controles;
}

/*
 * Méthode qui retourne un double représentant le d2 de la viewport des contrôles
 */
double View3D::getD2Controles() {
	return d2Controles;
}

/*
 * Méthode qui retourne un double représentant le delta1 de la viewport des contrôles
 */
double View3D::getDelta1Controles() {
	return delta1Controles;
}

/*
 * Méthode qui retourne un double représentant le delda2 de la viewport des contrôles
 */
double View3D::getDelta2Controles() {
	return delta2Controles;
}

/*
 * Méthode qui retourne un entier représentant le w global
 */
int View3D::getWGlobal() {
	return w_global;
}

/*
 * Méthode qui retourne un entier représentant le h global
 */
int View3D::getHGlobal() {
	return h_global;
}

/*
 * Méthode qui retourne un entier représentant la coordonnées 
 * Y du coin inférieur gauche de la viewport de jeu
 */
int View3D::getYCoinInferieurGaucheViewportJeu() {
	return yCoinInferieurGaucheViewportJeu;
}

/*
 * Méthode qui retourne un entier représentant la largeur de la viewport de jeu
 */
int View3D::getLargeurViewportJeu() {
	return largeurViewportJeu;
}

/*
 * Méthode qui retourne un entier représentant la hauteur de la viewport de jeu
 */
int View3D::getHauteurViewportJeu() {
	return hauteurViewportJeu;
}

/*
 * Méthode qui gère la projection de la viewport de jeu
 */
void View3D::projectionViewportJeu() {
	double zoom = camera->getFacteurZoom();
	glOrtho(-(delta1Jeu / 2) * zoom, (delta1Jeu / 2) * zoom, -(delta2Jeu / 2) * zoom, (delta2Jeu / 2) * zoom, 1.0, 100.0);
}
