#pragma once

#include <iostream>
#include "Model.h"
#include "Utils.h"

class Texte {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Texte *instance;
	// Attibut qui retient l'instance du Model
	Model *model;
	// Attribut contenant un pointeur sur l'instance d'une GLUquadricObj (on utilise la m�me instance pour tout le projet)
	GLUquadricObj *quadric;
	/*
	 * M�thode qui convertis un entier r�cup�r� par param�tre en pointeur de caract�res
	 */
	char* convertirIntEnChar(int nb);
	/*
	 * Constructeur (Pattern Singleton)
	 */
	Texte();

public:
	/*
	 * Destructeur
	 */
	~Texte();
	/*
	 * Getter de l'instance (Pattern Singleton)
	 */
	static Texte *getInstance();
	/*
	 * M�thode qui affiche le niveau de la partie
	 */
	void afficherNiveau();
	/*
	 * M�thode qui affiche le score
	 */
	void afficherScore();
	/*
	 * M�thode qui affiche les vies du Pac-Man
	 */
	void afficherVies();
	/*
	 * M�thode qui affiche le mode du Pac-Man
	 */
	void afficherMode();
	/*
	 * M�thode qui affiche Game Over si la partie est perdue
	 */
	void afficherFin();
	/*
	 * M�thode qui affiche le texte 2D
	 */
	void afficher2D();
	/*
	 * M�thode qui affiche le texte Parall�le
	 */
	void afficherParallele();
	/*
	 * M�thode qui affiche le texte Perspective
	 */
	void afficherPerspective();
	/*
	 * M�thode qui affiche le texte Rejouer
	 */
	void afficherRejouer();
	/*
	 * M�thode qui affiche le texte Quitter
	 */
	void afficherQuitter();
	/*
	 * M�thode qui affiche le caract�re +
	 */
	void afficherPlus();
	/*
	 * M�thode qui affiche le caract�re -
	 */
	void afficherMoins();
};