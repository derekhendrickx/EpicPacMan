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
	 * Méthode qui initialise les displays lists
	 */
	void init();
	/*
	 * Méthode qui contient les instructions OpenGL pour la display list d'un mur en 3D
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
	 * Méthode qui retourne l'instance de la classe (Pattern Singleton) sous forme de pointeur
	 */
	static Mur *getInstance();
	/*
	 * Méthode qui crée un cube en 3D avec tesselation (c.à.d. cube subdivisé en plusieurs faces) pour permette un plus bel éclairage, on lui passe en paramètre les
	 * coordonnées du cube à créer et le nombres de tranches
	 */
	void creerCube(double x1, double x2, double y1, double y2, double z1, double z2, int slices);
	/*
	 * Méthode qui dessine un mur Nord en 2D
	 */
	void dessinerMurNord2D();
	/*
	 * Méthode qui dessine un mur Nord-Ouest en 2D
	 */
	void dessinerMurNordOuest2D();
	/*
	 * Méthode qui dessine un mur Est et un mur Ouest en 2D
	 */
	void dessinerMurEstOuest2D();
	/*
	 * Méthode qui dessine un mur Nord en 3D
	 */
	void dessinerMurNord3D();
	/*
	 * Méthode qui dessine un mur Nord-Ouest en 3D
	 */
	void dessinerMurNordOuest3D();
	/*
	 * Méthode qui dessine un mur Est et un mur Ouest en 3D
	 */
	void dessinerMurEstOuest3D();
};

