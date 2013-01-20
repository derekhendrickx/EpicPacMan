#include "UI.h"

/*
 * Constructeur
 */
UI::UI(void)
{
	fleche = Fleche::getInstance();
	bouton = Bouton::getInstance();
	texte = Texte::getInstance();
}

/*
 * Destructeur
 */
UI::~UI(void)
{
	// Vide
}

/*
 * M�thode qui affiche les diff�rents �l�ments de contr�les du Pac-Man et de la partie
 */
void UI::dessinerBoutons() {
	vue2D();
	parallele();
	perspective();
	rejouer();
	quitter();
	zoomPlus();
	zoomMoins();
}

/*
 * M�thode qui affiche le bouton pour passer en 2D
 */
void UI::vue2D() {
	// Bouton pour passer en 2D
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(0.0, 15.0, 0.0);
			bouton->dessinerBouton(1);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, 7.5, 0.0);
			texte->afficher2D();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche le bouton pour passer en 3D parall�le
 */
void UI::parallele() {
	// Bouton parall�le
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(0.0, 11.0, 0.0);
			bouton->dessinerBouton(1);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, 5.5, 0.0);
			texte->afficherParallele();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche le bouton pour passer en 3D perspective
 */
void UI::perspective() {
	// Bouton perspective
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(0.0, 7.0, 0.0);
			bouton->dessinerBouton(1);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, 3.5, 0.0);
			texte->afficherPerspective();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche le bouton pour rejouer
 */
void UI::rejouer() {
	// Bouton rejouer
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(0.0, 3.0, 0.0);
			bouton->dessinerBouton(1);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, 1.5, 0.0);
			texte->afficherRejouer();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche le bouton pour quitter
 */
void UI::quitter() {
	// Bouton quitter
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(0.0, -1.0, 0.0);
			bouton->dessinerBouton(1);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, -0.5, 0.0);
			texte->afficherQuitter();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche le bouton pour zoomer en avant
 */
void UI::zoomPlus() {
	// Bouton + pour le zoom
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(-2.0, -5.0, 0.0);
			bouton->dessinerBouton(2);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, -2.5, 0.0);
			texte->afficherPlus();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche le bouton pour zoomer en arri�re
 */
void UI::zoomMoins() {
	// Bouton - pour le zoom
	glPushMatrix();
		// Bouton
		glPushMatrix();
			glTranslated(2.0, -5.0, 0.0);
			bouton->dessinerBouton(2);
		glPopMatrix();

		// Texte
		glPushMatrix();
			glTranslated(0.0, -2.5, 0.0);
			texte->afficherMoins();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui dessine les contr�les pour la souris
 */
void UI::dessinerFlechesDeControle() {
	glTranslated(0.0, -8.5, 0.0);
	glPushMatrix();
		// Fond
		glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 0.3);
			glVertex2d(-3.0, -5.0);
			glVertex2d(3.0, -5.0);
			glVertex2d(3.0, 1.0);
			glVertex2d(-3.0, 1.0);
		glEnd();

		// Fl�che haut
		glPushMatrix();
			fleche->dessinerFleche();
		glPopMatrix();
		
		// Fl�che droite
		glPushMatrix();
			glTranslated(2.0, -2.0, 0.0);
			glRotated(-90, 0.0, 0.0, 1.0);
			fleche->dessinerFleche();
		glPopMatrix();

		// Fl�che bas
		glPushMatrix();
			glTranslated(0.0, -4.0, 0.0);
			glRotated(180, 0.0, 0.0, 1.0);
			fleche->dessinerFleche();
		glPopMatrix();
		
		// Fl�che gauche
		glPushMatrix();
			glTranslated(-2.0, -2.0, 0.0);
			glRotated(90, 0.0, 0.0, 1.0);
			fleche->dessinerFleche();
		glPopMatrix();
	glPopMatrix();
}

/*
 * M�thode qui affiche les diff�rents informations sur la partie et le Pac-Man
 */
void UI::affichageInfos() {
	texte->afficherNiveau();
	texte->afficherScore();
	texte->afficherVies();
	texte->afficherMode();
	texte->afficherFin();
}
