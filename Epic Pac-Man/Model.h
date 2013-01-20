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
	// Attribut contenant un tableau de pointeurs sur les instances des fantômes
	FantomeModel *fantome;
	// Attribut contenant un pointeur sur l'instance du Labyrinthe
	Labyrinthe *labyrinthe;
	// Niveau de progression dans le jeu
	int niveau;
	// Score courant dans le jeu
	int score;

	/*
	 * Constructeur qui initialise une Quadric, une instance de Pac-Man,
	 * le niveau à 1, le score à 0 et initialise le labyrinthe (Pattern Singleton)
	 */
	Model();
public:
	/*
	 * Destructeur qui libère la mémoire occupée par le labyrinthe, les pastilles, la quadric et le Pac-Man
	 */
	~Model();

	/*
	 * Méthode qui retourne l'instance du modèle (Pattern Singleton) sous forme de pointeur
	 */
	static Model *getInstance();

	/*
	 * Méthode qui retourne une string contenant le nom de fichier de configuration du labyrinthe
	 */
	string recupererFichierConfig();

	/*
	 * Méthode qui charge un labyrinthe à partir d'un fichier
	 */
	void initLabyrinthe(string fichierConfig);

	/*
	 * Méthode qui retourne l'instance du Pac-Man sous forme de pointeur
	 */
	PacManModel *getPacman();

	/*
	 * Méthode qui retourne l'instance du Fantôme sous forme de pointeur
	 */
	FantomeModel *getFantome();

	/*
	 * Méthode qui retourne l'instance du Labyrinthe sous forme de pointeur
	 */
	Labyrinthe *getLabyrinthe();

	/*
	 * Méthode qui retourne le niveau de progression dans le jeu
	 */
	int getNiveau();

	/*
	 * Méthode qui modifie le niveau de progression dans le jeu
	 */
	void setNiveau(int nouveauNiveau);

	/*
	 * Méthode qui incrémente le niveau de progression dans le jeu 
	 * en fonction du nouveau niveau passé en paramètre
	 */
	void incNiveau(int lvl);

	/*
	 * Méthode qui retourne le score courant
	 */
	int getScore();

	/*
	 * Méthode qui incrémente le score en fonction du pas passé en paramètre
	 */
	void incScore(int pas);

	/*
	 * Méthode qui modifie le score en fonction d'un nouveau score passé en paramètre
	 */
	void setScore(int newScore);

	/*
	 * Méthode qui permet de gérer le changement de niveau, un changement de niveau
	 * implique un changement de labyrinthe.
	 * return true s'il est possible de changer de niveau, false sinon.
	 */
	bool chargerNiveau(int niveauACharger);
};
