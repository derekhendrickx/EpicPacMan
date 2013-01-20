#pragma once

#include "View.h"

class View3D: public View
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static View *instance;
	Camera *camera;
	// Attibut qui retient l'instance du Model pour accéder aux données modifiables
	Model *model;
	// Attibut qui retient l'instance du Dessin pour accéder aux méthodes de dessins
	Dessin *dessin;
	// Attibut qui retient l'instance d'UI pour accéder aux méthodes d'affichage
	UI *ui;
	// Attributs pour stocker hauteur et largeur de la fenêtre d'écran
	int h_global, w_global;
	// Attribut pour le d1 de la viewport des contrôles du jeu
	int d1Controles;
	// Attribut pour le d2 de la viewport des contrôles du jeu
	int d2Controles;
	// Attribut pour le delta1 de la viewport des contrôles du jeu
	int delta1Controles;
	// Attribut pour le delta2 de la viewport des contrôles du jeu
	int delta2Controles;
	// Attribut pour le delta1 et delta2 de la viewport de jeu
	double delta1Jeu, delta2Jeu;
	// Coordonnée Y du coin inférieur gauche de la viewport de jeu
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
	 * Méthode qui définis une première viewport contenant le jeu
	 */
	void viewportJeu();

	/*
	 * Méthode qui définis une deuxième viewport contenant les informations sur le jeu
	 */
	void viewportInfosJeu();

	/*
	 * Méthode qui définis une deuxième viewport contenant les contrôles du jeu
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
	 * Méthode qui définit le modèle pour affichage à l'écran
	 */
	void display();
	/*
	 * Méthode appelé en cas de redimensionnement de la fenêtre d'écran
	 */
	void reshape(int w, int h);
	/*
	 * Méthode qui rafraichit l'affichage
	 */
	void redraw();
	/*
	 * Méthode qui retourne un double représentant le d1 de la viewport des contrôles
	 */
	double getD1Controles();
	/*
	 * Méthode qui retourne un double représentant le d2 de la viewport des contrôles
	 */
	double getD2Controles();
	/*
	 * Méthode qui retourne un double représentant le delta1 de la viewport des contrôles
	 */
	double getDelta1Controles();
	/*
	 * Méthode qui retourne un double représentant le delda2 de la viewport des contrôles
	 */
	double getDelta2Controles();
	/*
	 * Méthode qui retourne un entier représentant le w global
	 */
	int getWGlobal();
	/*
	 * Méthode qui retourne un entier représentant le h global
	 */
	int getHGlobal();
	/*
	 * Méthode qui retourne un entier représentant la coordonnées 
	 * Y du coin inférieur gauche de la viewport de jeu
	 */
	int getYCoinInferieurGaucheViewportJeu();
	/*
	 * Méthode qui retourne un entier représentant la largeur de la viewport de jeu
	 */
	int getLargeurViewportJeu();
	/*
	 * Méthode qui retourne un entier représentant la hauteur de la viewport de jeu
	 */
	int getHauteurViewportJeu();
	/*
	 * Méthode qui gère la projection de la viewport de jeu
	 */
	void projectionViewportJeu();
};

