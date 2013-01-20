#pragma once

#include "Utils.h"
#include "Model.h"

class PacMan
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static PacMan *instance;
	// Attribut contenant un pointeur sur l'instance d'une GLUquadricObj (on utilise la même instance pour tout le projet)
	GLUquadricObj *quadric;
	// Attribut pour la display list
	int pac;
	/*
	 * Méthode qui initialise la display list
	 */
	void init();
	/*
	 * Méthode qui contient les instructions OpenGL pour la display list du Pac-Man en 3D
	 */
	void pacman3D();
	/*
	 * Constructeur (Pattern Singleton)
	 */
	PacMan(void);
public:
	/*
	 * Destructeur
	 */
	~PacMan(void);
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static PacMan *getInstance();
	/*
	 * Méthode qui dessine le Pac-Man en 2D
	 */
	void dessinerPacman2D(PacManModel *pacman);
	/*
	 * Méthode qui dessine le Pac-Man en 3D
	 */
	void dessinerPacman3D(PacManModel *pacman);
};

