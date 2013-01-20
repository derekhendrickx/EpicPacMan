#pragma once

#include "Utils.h"
#include "PacManModel.h"
#include "FantomeModel.h"
#include "Labyrinthe.h"

#include <iostream>
#include <fstream>
#include <sstream>

class Model {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Model *instance;
	// Attribut contenant un pointeur sur l'instance du Pac-Man
	PacManModel *pacman;
	// Attribut contenant un tableau de pointeurs sur les instances des fant�mes
	FantomeModel *fantome;
	// Attribut contenant un pointeur sur l'instance du Labyrinthe
	Labyrinthe *labyrinthe;
	// Niveau de progression dans le jeu
	int niveau;
	// Score courant dans le jeu
	int score;

	/*
	 * Constructeur qui initialise une Quadric, une instance de Pac-Man,
	 * le niveau � 1, le score � 0 et initialise le labyrinthe (Pattern Singleton)
	 */
	Model();
public:
	/*
	 * Destructeur qui lib�re la m�moire occup�e par le labyrinthe, les pastilles, la quadric et le Pac-Man
	 */
	~Model();

	/*
	 * M�thode qui retourne l'instance du mod�le (Pattern Singleton) sous forme de pointeur
	 */
	static Model *getInstance();

	/*
	 * M�thode qui retourne une string contenant le nom de fichier de configuration du labyrinthe
	 */
	string recupererFichierConfig();

	/*
	 * M�thode qui charge un labyrinthe � partir d'un fichier
	 */
	void initLabyrinthe(string fichierConfig);

	/*
	 * M�thode qui retourne l'instance du Pac-Man sous forme de pointeur
	 */
	PacManModel *getPacman();

	/*
	 * M�thode qui retourne l'instance du Fant�me sous forme de pointeur
	 */
	FantomeModel *getFantome();

	/*
	 * M�thode qui retourne l'instance du Labyrinthe sous forme de pointeur
	 */
	Labyrinthe *getLabyrinthe();

	/*
	 * M�thode qui retourne le niveau de progression dans le jeu
	 */
	int getNiveau();

	/*
	 * M�thode qui modifie le niveau de progression dans le jeu
	 */
	void setNiveau(int nouveauNiveau);

	/*
	 * M�thode qui incr�mente le niveau de progression dans le jeu 
	 * en fonction du nouveau niveau pass� en param�tre
	 */
	void incNiveau(int lvl);

	/*
	 * M�thode qui retourne le score courant
	 */
	int getScore();

	/*
	 * M�thode qui incr�mente le score en fonction du pas pass� en param�tre
	 */
	void incScore(int pas);

	/*
	 * M�thode qui modifie le score en fonction d'un nouveau score pass� en param�tre
	 */
	void setScore(int newScore);

	/*
	 * M�thode qui permet de g�rer le changement de niveau, un changement de niveau
	 * implique un changement de labyrinthe.
	 * return true s'il est possible de changer de niveau, false sinon.
	 */
	bool chargerNiveau(int niveauACharger);
};
