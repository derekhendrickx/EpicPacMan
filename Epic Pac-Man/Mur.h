#pragma once

#include "Utils.h"

class Mur
{
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Mur *instance;
	// Attributs pour la display list
	int mur;
	/*
	 * M�thode qui initialise les displays lists
	 */
	void init();
	/*
	 * M�thode qui contient les instructions OpenGL pour la display list d'un mur en 3D
	 */
	void mur3D();
	/*
	 * Constructeur (Pattern Singleton)
	 */
	Mur();
public:
	/*
	 * Destructeur
	 */
	~Mur();
	/*
	 * M�thode qui retourne l'instance de la classe (Pattern Singleton) sous forme de pointeur
	 */
	static Mur *getInstance();
	/*
	 * M�thode qui cr�e un cube en 3D avec tesselation (c.�.d. cube subdivis� en plusieurs faces) pour permette un plus bel �clairage, on lui passe en param�tre les
	 * coordonn�es du cube � cr�er et le nombres de tranches
	 */
	void creerCube(double x1, double x2, double y1, double y2, double z1, double z2, int slices);
	/*
	 * M�thode qui dessine un mur Nord en 2D
	 */
	void dessinerMurNord2D();
	/*
	 * M�thode qui dessine un mur Nord-Ouest en 2D
	 */
	void dessinerMurNordOuest2D();
	/*
	 * M�thode qui dessine un mur Est et un mur Ouest en 2D
	 */
	void dessinerMurEstOuest2D();
	/*
	 * M�thode qui dessine un mur Nord en 3D
	 */
	void dessinerMurNord3D();
	/*
	 * M�thode qui dessine un mur Nord-Ouest en 3D
	 */
	void dessinerMurNordOuest3D();
	/*
	 * M�thode qui dessine un mur Est et un mur Ouest en 3D
	 */
	void dessinerMurEstOuest3D();
};

