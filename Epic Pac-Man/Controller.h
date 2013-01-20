#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "windows.h"

#include "Utils.h"

#include "Model.h"
#include "ViewContext.h"
#include "View2D.h"
#include "View3D.h"
#include "View3DPerspective.h"
#include "Camera.h"

class Controller {
private:
	// Attibut qui retient l'instance de la classe (Pattern Singleton)
	static Controller *instance;
	// Attibut qui retient l'instance du Model
	Model *model;
	// Attibut qui retient l'instance de la View
	View  *view;
	// Attribut qui retient l'instance du pacman
	PacManModel *pacman;
	// Attribut qui retient l'instance du fant�me
	FantomeModel *fantome;
	// Attribut qui retient l'instance du labyrinthe
	Labyrinthe *labyrinthe;
	// Permet de g�rer l'entr�e/la sortie du mode super pour le pacman et le fant�me
	int compteur;

	/*
	 * M�thode qui retire la pastille de la structure de donn�es
	 * en fonction de sa position x et y pass�e en param�tre
	 */
	void manger(int y, int x);
	/*
	 * M�thode qui change le mode de la vue en : 3D parall�le ou 3D perspective
	 */
	void changerMode();
	/*
	 * M�thode qui change la vue en 2D ou en 3D en fonction du mode d�sir� (3D parall�re ou 3D perspective) pass� en param�tre
	 */
	void changerVue(int mode);
	/*
	 * M�thode qui r�initialise la partie
	 */
	void reinitialiser();
	/*
	 * M�thode qui quitte la partie
	 */
	void quitter();
	/*
	 * M�thode qui d�place le Pac-Man
	 */
	void deplacerPacman();
	/*
	 * M�thode qui d�place le Pac-Man en fonction de son orientation
	 */
	void gererOrientationPacman(double positionXPacman, double positionYPacman);
	/*
	 * M�thode qui d�place le Fant�me
	 */
	void deplacerFantome();
	/*
	 * G�re les collisions entre le pacman et le fant�me
	 */
	void gererCollisionsPacmanFantome();
	/*
	 * M�thode qui initialise les pastilles dans le labyrinthe
	 */
	void initPastilles();
	/*
	 * M�thode qui indique si le Fant�me est bloqu� par un mur du labyrinthe, elle renvoie
	 * -1 s'il n'y a pas de collision, sinon elle renvoie la nouvelle direction (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
	 */
	int collision();
	/*
	 * M�thode qui g�re l'orientation du fant�me
	 */
	void gererOrientationFantome();
	/*
	 * Constructeur qui demande une instance du Model et de la View et qui initialise l'animation � 1
	 * et la fin de partie � false (Pattern Singleton)
	 */
	Controller();

public:
	/*
	 * Destructeur
	 */
	~Controller();
	/*
	 * M�thode qui g�re les contr�les de la souris en fonction du bouton, de son �tat et de sa positon x et y
	 */
	void mouse(int button, int state, int x, int y);
	/*
	 * M�thode qui g�re les d�placements du pacman en fonction de la direction
	 * s�lectionn�e par l'utilisateur via un clic de souris (clic gauche)
	 */
	void gererControlesPacman(int x_dessin, int y_dessin);
	/*
	 * M�thode qui g�re le click au centre de la sc�ne pour faire tourner le labyrinthe
	 */
	void mousePicking(int button, int state, int x_ecran, int y_ecran);
	/*
	 * M�thode qui g�re les fl�ches du clavier en fonction de la touche et sa position x et y
	 */
	void special(int key, int x, int y);
	/*
	 * M�thode qui g�re les contr�les du clavier en fonction de la touche et sa position x et y
	 */
	void keyboard(unsigned char key, int x, int y);
	/*
	 * M�thode qui anime la bouche du Pac-Man
	 */
	void animateMouthPacman();
	/*
	 * M�thode qui appelle la m�thode qui d�place le Pac-Man
	 */
	void animateDisplay();
	/*
	 * M�thode qui g�re le mode du pacman (super, normal) et le mode du fant�me (super, normal)
	 */
	void animateMode();
	/*
	 * M�thode qui g�re la rotation du labyrinthe
	 */
	void animateRotation();
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static Controller *getInstance();
};
