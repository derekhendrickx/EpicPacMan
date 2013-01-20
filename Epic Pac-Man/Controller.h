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
	// Attribut qui retient l'instance du fantôme
	FantomeModel *fantome;
	// Attribut qui retient l'instance du labyrinthe
	Labyrinthe *labyrinthe;
	// Permet de gérer l'entrée/la sortie du mode super pour le pacman et le fantôme
	int compteur;

	/*
	 * Méthode qui retire la pastille de la structure de données
	 * en fonction de sa position x et y passée en paramètre
	 */
	void manger(int y, int x);
	/*
	 * Méthode qui change le mode de la vue en : 3D parallèle ou 3D perspective
	 */
	void changerMode();
	/*
	 * Méthode qui change la vue en 2D ou en 3D en fonction du mode désiré (3D parallère ou 3D perspective) passé en paramètre
	 */
	void changerVue(int mode);
	/*
	 * Méthode qui réinitialise la partie
	 */
	void reinitialiser();
	/*
	 * Méthode qui quitte la partie
	 */
	void quitter();
	/*
	 * Méthode qui déplace le Pac-Man
	 */
	void deplacerPacman();
	/*
	 * Méthode qui déplace le Pac-Man en fonction de son orientation
	 */
	void gererOrientationPacman(double positionXPacman, double positionYPacman);
	/*
	 * Méthode qui déplace le Fantôme
	 */
	void deplacerFantome();
	/*
	 * Gère les collisions entre le pacman et le fantôme
	 */
	void gererCollisionsPacmanFantome();
	/*
	 * Méthode qui initialise les pastilles dans le labyrinthe
	 */
	void initPastilles();
	/*
	 * Méthode qui indique si le Fantôme est bloqué par un mur du labyrinthe, elle renvoie
	 * -1 s'il n'y a pas de collision, sinon elle renvoie la nouvelle direction (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
	 */
	int collision();
	/*
	 * Méthode qui gère l'orientation du fantôme
	 */
	void gererOrientationFantome();
	/*
	 * Constructeur qui demande une instance du Model et de la View et qui initialise l'animation à 1
	 * et la fin de partie à false (Pattern Singleton)
	 */
	Controller();

public:
	/*
	 * Destructeur
	 */
	~Controller();
	/*
	 * Méthode qui gère les contrôles de la souris en fonction du bouton, de son état et de sa positon x et y
	 */
	void mouse(int button, int state, int x, int y);
	/*
	 * Méthode qui gère les déplacements du pacman en fonction de la direction
	 * sélectionnée par l'utilisateur via un clic de souris (clic gauche)
	 */
	void gererControlesPacman(int x_dessin, int y_dessin);
	/*
	 * Méthode qui gère le click au centre de la scène pour faire tourner le labyrinthe
	 */
	void mousePicking(int button, int state, int x_ecran, int y_ecran);
	/*
	 * Méthode qui gère les flèches du clavier en fonction de la touche et sa position x et y
	 */
	void special(int key, int x, int y);
	/*
	 * Méthode qui gère les contrôles du clavier en fonction de la touche et sa position x et y
	 */
	void keyboard(unsigned char key, int x, int y);
	/*
	 * Méthode qui anime la bouche du Pac-Man
	 */
	void animateMouthPacman();
	/*
	 * Méthode qui appelle la méthode qui déplace le Pac-Man
	 */
	void animateDisplay();
	/*
	 * Méthode qui gère le mode du pacman (super, normal) et le mode du fantôme (super, normal)
	 */
	void animateMode();
	/*
	 * Méthode qui gère la rotation du labyrinthe
	 */
	void animateRotation();
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static Controller *getInstance();
};
