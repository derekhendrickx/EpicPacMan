#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

#include "PacManModel.h"
#include "FantomeModel.h"

using namespace std;

class Labyrinthe {
private:
	// Hauteur du labyrinthe
	int hauteurLabyrinthe;
	// Largeur du labyrinthe
	int largeurLabyrinthe;
	// Propriétées de la viewport du Jeu
	double d1, d2, delta1, delta2;
	// Nombre de pastilles au total
	int nbPastillesTotal;
	// Nombre de pastilles restantes
	int nbPastillesRestantes;
	// Tableau à 2 dimensions qui contient les formes du labyrinthe
	int **murs;
	// Tableau à 2 dimensions qui contient les pastilles contenues dans le labyrinthe
	int **pastilles;
	// Indique si le labyrinthe est en rotation ou non
	bool rotating;

public:
	/*
	 * Constructeur
	 */
	Labyrinthe();

	/*
	 * Destructeur qui libère la mémoire occupée par le labyrinthe et les pastilles
	 */
	~Labyrinthe();

	/*
	 * Méthode qui surcharge l'opérateur >> pour initialiser le labyrinthe passé en 
	 * paramètre en fonction du fichier de configuration passé en paramètre
	 */
	friend istream& operator>>(istream &config, Labyrinthe &labyrinthe);

	/*
	 * Méthode qui retourne la hauteur du labyrinthe
	 */
	int getHauteurLabyrinthe();

	/*
	 * Méthode qui retourne la largeur du labyrinthe
	 */
	int getLargeurLabyrinthe();

	/*
	 * Méthode qui retourne la hauteur maximum possible pour éviter au Pac-Man de sortir du labyrinthe
	 */
	int getHauteurLabyrintheMax();

	/*
	 * Méthode qui retourne la largeur maximum possible pour éviter au Pac-Man de sortir du labyrinthe
	 */
	int getLargeurLabyrintheMax();

	/*
	 * Méthode qui retourne la propriétée d1 de la viewport du Jeu
	 */
	double getD1();

	/*
	 * Méthode qui retourne la propriétée d2 de la viewport du Jeu
	 */
	double getD2();

	/*
	 * Méthode qui retourne la propriétée delta1 de la viewport du Jeu
	 */
	double getDelta1();

	/*
	 * Méthode qui retourne la propriétée delta2 de la viewport du Jeu
	 */
	double getDelta2();

	/*
	 * Méthode qui retourne la forme contenue dans le tableau des murs à l'indice x et y passé en paramètre
	 */
	int getMur(int x, int y);

	/*
	 * Méthode qui retourne le type d'élément contenu dans le tableau des pastilles 
	 * à l'indice x et y passé en paramètre
	 */
	int getPastille(int x, int y);

	/*
	 * Méthode qui modifie le type d'élément contenu dans le tableau des pastilles 
	 * à l'indice x et y passé en paramètre (2=super pastille, 1=pastille, 0=pas de pastille, 
	 * -1=emplacement vide anciennement occupé par une pastille, -2=emplacement vide anciennement 
	 * occupé par une super pastille)
	 */
	void setPastille(int x, int y, int valeur);

	/*
	 * Méthode qui retourne true si le labyrinthe est ouvert à l'indice x et y passé en paramètre, false sinon
	 */
	bool isOuvert(double y, double x);

	/*
	 * Méthode qui retourne le nombre de pastilles total dans le labyrinthe
	 */
	int getNbPastillesTotal();

	/*
	 * Méthode qui retourne le nombres de pastilles restantes dans le labyrinthe
	 */
	int getNbPastillesRestantes();

	/*
	 * Méthode qui modifie le nombres de pastilles restantes en fonction du nouveau 
	 * nombre de pastilles restantes passé en paramètre
	 */
	void setNbPastillesRestantes(int nbPastilles);

	/*
	 * Méthode qui décrémente le nombres de pastilles restantes
	 */
	void decNbPastillesRestantes();

	/*
	 * Méthode qui renvoie true si le labyrinthe est en rotation, false sinon
	 */
	bool isRotating();

	/*
	 * Méthode qui modifie la rotation du labyrinthe (la démarre ou la stoppe)
	 */
	void setRotating(bool rotate);
};
