#pragma once

#include <iostream>
#include <cmath>

#include "Utils.h"

// Enumération qui représente l'état de la bouche du Pac-Man pour pouvoir l'animer
enum Etat{MOUTH_OPENED, MOUTH_CLOSED};

class PacManModel {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static PacManModel *instance;
	// Position courante du Pac-Man dans le labyrinthe
	double positionXInitiale, positionYInitiale;
	// Position courante du Pac-Man dans le labyrinthe
	double positionX, positionY;
	// Indique si le Pac-Man est en mode super (invincible) ou en mode normal
	bool super;
	// Indique l'orientation du Pac-Man
	int orientation;
	// Indique l'orientation suivante du Pac-Man
	int orientationSuivante;
	// Indique l'état du Pac-Man
	Etat etat;
	// Indique le nombre de vies restantes
	int nbVies;
	// Indique si la bouche du Pa-Man doit être animée ou non
	bool mouthAnimated;
	// Indique si la partie est perdue ou non
	bool gameOver;
	/*
	 * Constructeur (Pattern Singleton)
	 */
	PacManModel();
public:
	/*
	 * Destructeur
	 */
	~PacManModel();
	/*
	 * Méthode qui retourne de l'instance du modèle (Pattern Singleton) sous forme de pointeur
	 */
	static PacManModel *getInstance();

	/*
	 * Méthode qui retourne la position x initiale du Pac-Man
	 */
	double getPositionXInitiale();

	/*
	 * Méthode qui retourne la position y initiale du Pac-Man
	 */
	double getPositionYInitiale();

	/*
	 * Méthode qui modifie la position x initiale du Pac-Man en fonction d'un entier passé en paramètre
	 */
	void setPositionXInitiale(double x);

	/*
	 * Méthode qui modifie la position y initiale du Pac-Man en fonction d'un entier passé en paramètre
	 */
	void setPositionYInitiale(double y);

	/*
	 * Méthode qui retourne la position x actuelle du Pac-Man
	 */
	double getPositionX();

	/*
	 * Méthode qui retourne la position y actuelle du Pac-Man
	 */
	double getPositionY();

	/*
	 * Méthode qui modifie la position x actuelle du Pac-Man en fonction d'un entier passé en paramètre
	 */
	void setPositionX(double x);

	/*
	 * Méthode qui modifie la position y actuelle du Pac-Man en fonction d'un entier passé en paramètre
	 */
	void setPositionY(double y);

	/*
	 * Méthode qui retourne l'orientation du Pac-Man
	 */
	int getOrientation();

	/*
	 * Méthode qui modifie l'orientation du Pac-Man en fonction 
	 * de la nouvelle orientation passée en paramètre
	 */
	void setOrientation(int nouvelleOrientation);

	/*
	 * Méthode qui retourne l'orientation suivante du Pac-Man
	 */
	int getOrientationSuivante();

	/*
	 * Méthode qui modifie l'orientation suivante du Pac-Man en fonction 
	 * de la nouvelle orientation passée en paramètre
	 */
	void setOrientationSuivante(int nouvelleOrientationSuivante);

	/*
	 * Méthode qui retourne l'état de la bouche du Pac-Man
	 */
	Etat getEtat();

	/*
	 * Méthode qui modifie l'état de la bouche du Pac-Man en fonction 
	 * du nouvel état passé en paramètre
	 */
	void setEtat(Etat nouvelEtat);

	/*
	 * Méthode qui retourne true si le Pac-Man est dans le mode super (invincible), false sinon
	 */
	bool isSuper();

	/*
	 * Méthode qui modifie le mode du Pac-Man en fonction d'un boolean passé en 
	 * paramètre représentant le nouveau mode
	 */
	void setSuper(bool isSuper);

	/*
	 * Méthode qui incrémente le nombre de pas que le Pac-Man peut effectuer en mode super
	 */
	void incNbPas();

	/*
	 * Méthode qui retourne le nombre de vies restantes
	 */
	int getNbVies();

	/*
	 * Méthode qui incrémente le nombre de vies restantes
	 */
	void incNbVies();

	/*
	 * Méthode qui décrémente le nombre de vies restantes
	 */
	void decNbVies();

	/*
	 * Méthode qui modifie le nombre de vies du Pac-Man en fonction 
	 * d'un nouveau nombre de vies passé en paramètre
	 */
	void setNbVies(int newNbVies);

	/*
	 * Méthode qui retourne true si la bouche du Pac-Man est animée, false sinon
	 */
	bool isMouthAnimated();

	/*
	 * Méthode qui modifie l'état de la bouche du Pac-Man en fonction d'un boolean 
	 * passé en paramètre représentant le nouvel état
	 */
	void setMouthAnimated(bool animated);

	/*
	 * Méthode qui retourne true si la partie est perdue, false sinon
	 */
	bool isGameOver();

	/*
	 * Méthode fait passer l'attribut gameOver à false pour indiquer
	 * que la partie n'a pas été perdue
	 */
	void notGameOver();
};

