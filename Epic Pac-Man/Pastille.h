#pragma once

#include "Utils.h"

class Pastille
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Pastille *instance;
	// Attribut contenant un pointeur sur l'instance d'une GLUquadricObj (on utilise la m�me instance pour tout le projet)
	GLUquadricObj *quadric;
	// Attribut pour les displays lists
	int pastille, superPastille;
	/*
	 * M�thode qui initialise les displays lists
	 */
	void init();
	/*
	 * M�thode qui contient les instructions OpenGL pour la display list d'une pastille en 3D
	 */
	void pastille3D();
	/*
	 * M�thode qui contient les instructions OpenGL pour la display list d'une super pastille en 3D
	 */
	void superPastille3D();
	/*
	 * Constructeur
	 */
	Pastille(void);
public:
	/*
	 * Destructeur
	 */
	~Pastille(void);
	/*
	 * M�thode qui retourne l'instance de la classe (Pattern Singleton) sous forme de pointeur
	 */
	static Pastille *getInstance();
	/*
	 * M�thode qui dessine une pastille en 2D
	 */
	void dessinerPastille2D();
	/*
	 * M�thode qui dessine une super pastille en 2D
	 */
	void dessinerSuperPastille2D();
	/*
	 * M�thode qui dessine une pastille en 3D
	 */
	void dessinerPastille3D();
	/*
	 * M�thode qui dessine une super pastille en 3D
	 */
	void dessinerSuperPastille3D();
};

