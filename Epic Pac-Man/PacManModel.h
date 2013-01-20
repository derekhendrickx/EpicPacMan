#pragma once

#include <iostream>
#include <cmath>

#include "Utils.h"

// Enum�ration qui repr�sente l'�tat de la bouche du Pac-Man pour pouvoir l'animer
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
	// Indique l'�tat du Pac-Man
	Etat etat;
	// Indique le nombre de vies restantes
	int nbVies;
	// Indique si la bouche du Pa-Man doit �tre anim�e ou non
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
	 * M�thode qui retourne de l'instance du mod�le (Pattern Singleton) sous forme de pointeur
	 */
	static PacManModel *getInstance();

	/*
	 * M�thode qui retourne la position x initiale du Pac-Man
	 */
	double getPositionXInitiale();

	/*
	 * M�thode qui retourne la position y initiale du Pac-Man
	 */
	double getPositionYInitiale();

	/*
	 * M�thode qui modifie la position x initiale du Pac-Man en fonction d'un entier pass� en param�tre
	 */
	void setPositionXInitiale(double x);

	/*
	 * M�thode qui modifie la position y initiale du Pac-Man en fonction d'un entier pass� en param�tre
	 */
	void setPositionYInitiale(double y);

	/*
	 * M�thode qui retourne la position x actuelle du Pac-Man
	 */
	double getPositionX();

	/*
	 * M�thode qui retourne la position y actuelle du Pac-Man
	 */
	double getPositionY();

	/*
	 * M�thode qui modifie la position x actuelle du Pac-Man en fonction d'un entier pass� en param�tre
	 */
	void setPositionX(double x);

	/*
	 * M�thode qui modifie la position y actuelle du Pac-Man en fonction d'un entier pass� en param�tre
	 */
	void setPositionY(double y);

	/*
	 * M�thode qui retourne l'orientation du Pac-Man
	 */
	int getOrientation();

	/*
	 * M�thode qui modifie l'orientation du Pac-Man en fonction 
	 * de la nouvelle orientation pass�e en param�tre
	 */
	void setOrientation(int nouvelleOrientation);

	/*
	 * M�thode qui retourne l'orientation suivante du Pac-Man
	 */
	int getOrientationSuivante();

	/*
	 * M�thode qui modifie l'orientation suivante du Pac-Man en fonction 
	 * de la nouvelle orientation pass�e en param�tre
	 */
	void setOrientationSuivante(int nouvelleOrientationSuivante);

	/*
	 * M�thode qui retourne l'�tat de la bouche du Pac-Man
	 */
	Etat getEtat();

	/*
	 * M�thode qui modifie l'�tat de la bouche du Pac-Man en fonction 
	 * du nouvel �tat pass� en param�tre
	 */
	void setEtat(Etat nouvelEtat);

	/*
	 * M�thode qui retourne true si le Pac-Man est dans le mode super (invincible), false sinon
	 */
	bool isSuper();

	/*
	 * M�thode qui modifie le mode du Pac-Man en fonction d'un boolean pass� en 
	 * param�tre repr�sentant le nouveau mode
	 */
	void setSuper(bool isSuper);

	/*
	 * M�thode qui incr�mente le nombre de pas que le Pac-Man peut effectuer en mode super
	 */
	void incNbPas();

	/*
	 * M�thode qui retourne le nombre de vies restantes
	 */
	int getNbVies();

	/*
	 * M�thode qui incr�mente le nombre de vies restantes
	 */
	void incNbVies();

	/*
	 * M�thode qui d�cr�mente le nombre de vies restantes
	 */
	void decNbVies();

	/*
	 * M�thode qui modifie le nombre de vies du Pac-Man en fonction 
	 * d'un nouveau nombre de vies pass� en param�tre
	 */
	void setNbVies(int newNbVies);

	/*
	 * M�thode qui retourne true si la bouche du Pac-Man est anim�e, false sinon
	 */
	bool isMouthAnimated();

	/*
	 * M�thode qui modifie l'�tat de la bouche du Pac-Man en fonction d'un boolean 
	 * pass� en param�tre repr�sentant le nouvel �tat
	 */
	void setMouthAnimated(bool animated);

	/*
	 * M�thode qui retourne true si la partie est perdue, false sinon
	 */
	bool isGameOver();

	/*
	 * M�thode fait passer l'attribut gameOver � false pour indiquer
	 * que la partie n'a pas �t� perdue
	 */
	void notGameOver();
};

