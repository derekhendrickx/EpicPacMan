#pragma once

#include "Utils.h"
#include "Model.h"

class Fantome
{
private:
	static Fantome *instance;
	// Attribut contenant un pointeur sur l'instance d'une GLUquadricObj (on utilise la même instance pour tout le projet)
	GLUquadricObj *quadric;
	// Attribut pour la display list
	int fantome;
	/*
	 * Méthode qui initialise la display list
	 */
	void init();
	/*
	 * Méthode qui contient les intructions OpenGL pour la display list du fantôme en 3D
	 */
	void fantome3D();
	/*
	 * Constructeur (Pattern Singleton)
	 */
	Fantome();

public:
	
	/*
	 * Destructeur
	 */
	~Fantome();
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static Fantome *getInstance();
	/*
	 * Méthode qui dessine le Pac-Man en 2D
	 */
	void dessinerFantome2D(FantomeModel *fantomeModel);
	/*
	 * Méthode qui dessine le Pac-Man en 2D
	 */
	void dessinerFantome3D(FantomeModel *fantomeModel);
};
