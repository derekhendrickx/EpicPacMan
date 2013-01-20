#pragma once

#include "View.h"

class View3D: public View
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static View *instance;
	Camera *camera;
	// Attibut qui retient l'instance du Model pour acc�der aux donn�es modifiables
	Model *model;
	// Attibut qui retient l'instance du Dessin pour acc�der aux m�thodes de dessins
	Dessin *dessin;
	// Attibut qui retient l'instance d'UI pour acc�der aux m�thodes d'affichage
	UI *ui;
	// Attributs pour stocker hauteur et largeur de la fen�tre d'�cran
	int h_global, w_global;
	// Attribut pour le d1 de la viewport des contr�les du jeu
	int d1Controles;
	// Attribut pour le d2 de la viewport des contr�les du jeu
	int d2Controles;
	// Attribut pour le delta1 de la viewport des contr�les du jeu
	int delta1Controles;
	// Attribut pour le delta2 de la viewport des contr�les du jeu
	int delta2Controles;
	// Attribut pour le delta1 et delta2 de la viewport de jeu
	double delta1Jeu, delta2Jeu;
	// Coordonn�e Y du coin inf�rieur gauche de la viewport de jeu
	int yCoinInferieurGaucheViewportJeu;
	// Largeur de la viewport de jeu
	int largeurViewportJeu;
	// Hauteur de la viewport de jeu
	int hauteurViewportJeu;

	/*
	 * Constructeur (Pattern Singleton)
	 */
	View3D(void);
	/*
	 * M�thode qui d�finis une premi�re viewport contenant le jeu
	 */
	void viewportJeu();

	/*
	 * M�thode qui d�finis une deuxi�me viewport contenant les informations sur le jeu
	 */
	void viewportInfosJeu();

	/*
	 * M�thode qui d�finis une deuxi�me viewport contenant les contr�les du jeu
	 */
	void viewportControles();
public:
	/*
	 * Destructeur
	 */
	~View3D(void);
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static View *getInstance();
	/* 
	 * M�thode qui d�finit le mod�le pour affichage � l'�cran
	 */
	void display();
	/*
	 * M�thode appel� en cas de redimensionnement de la fen�tre d'�cran
	 */
	void reshape(int w, int h);
	/*
	 * M�thode qui rafraichit l'affichage
	 */
	void redraw();
	/*
	 * M�thode qui retourne un double repr�sentant le d1 de la viewport des contr�les
	 */
	double getD1Controles();
	/*
	 * M�thode qui retourne un double repr�sentant le d2 de la viewport des contr�les
	 */
	double getD2Controles();
	/*
	 * M�thode qui retourne un double repr�sentant le delta1 de la viewport des contr�les
	 */
	double getDelta1Controles();
	/*
	 * M�thode qui retourne un double repr�sentant le delda2 de la viewport des contr�les
	 */
	double getDelta2Controles();
	/*
	 * M�thode qui retourne un entier repr�sentant le w global
	 */
	int getWGlobal();
	/*
	 * M�thode qui retourne un entier repr�sentant le h global
	 */
	int getHGlobal();
	/*
	 * M�thode qui retourne un entier repr�sentant la coordonn�es 
	 * Y du coin inf�rieur gauche de la viewport de jeu
	 */
	int getYCoinInferieurGaucheViewportJeu();
	/*
	 * M�thode qui retourne un entier repr�sentant la largeur de la viewport de jeu
	 */
	int getLargeurViewportJeu();
	/*
	 * M�thode qui retourne un entier repr�sentant la hauteur de la viewport de jeu
	 */
	int getHauteurViewportJeu();
	/*
	 * M�thode qui g�re la projection de la viewport de jeu
	 */
	void projectionViewportJeu();
};

