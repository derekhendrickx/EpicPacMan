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
	// Attribut contenant un pointeur sur l'instance d'une GLUquadricObj (on utilise la même instance pour tout le projet)
	GLUquadricObj *quadric;
	/*
	 * Méthode qui convertis un entier récupéré par paramètre en pointeur de caractères
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
	 * Méthode qui affiche le niveau de la partie
	 */
	void afficherNiveau();
	/*
	 * Méthode qui affiche le score
	 */
	void afficherScore();
	/*
	 * Méthode qui affiche les vies du Pac-Man
	 */
	void afficherVies();
	/*
	 * Méthode qui affiche le mode du Pac-Man
	 */
	void afficherMode();
	/*
	 * Méthode qui affiche Game Over si la partie est perdue
	 */
	void afficherFin();
	/*
	 * Méthode qui affiche le texte 2D
	 */
	void afficher2D();
	/*
	 * Méthode qui affiche le texte Parallèle
	 */
	void afficherParallele();
	/*
	 * Méthode qui affiche le texte Perspective
	 */
	void afficherPerspective();
	/*
	 * Méthode qui affiche le texte Rejouer
	 */
	void afficherRejouer();
	/*
	 * Méthode qui affiche le texte Quitter
	 */
	void afficherQuitter();
	/*
	 * Méthode qui affiche le caractère +
	 */
	void afficherPlus();
	/*
	 * Méthode qui affiche le caractère -
	 */
	void afficherMoins();
};