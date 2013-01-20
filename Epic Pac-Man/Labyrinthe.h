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
	// Propri�t�es de la viewport du Jeu
	double d1, d2, delta1, delta2;
	// Nombre de pastilles au total
	int nbPastillesTotal;
	// Nombre de pastilles restantes
	int nbPastillesRestantes;
	// Tableau � 2 dimensions qui contient les formes du labyrinthe
	int **murs;
	// Tableau � 2 dimensions qui contient les pastilles contenues dans le labyrinthe
	int **pastilles;
	// Indique si le labyrinthe est en rotation ou non
	bool rotating;

public:
	/*
	 * Constructeur
	 */
	Labyrinthe();

	/*
	 * Destructeur qui lib�re la m�moire occup�e par le labyrinthe et les pastilles
	 */
	~Labyrinthe();

	/*
	 * M�thode qui surcharge l'op�rateur >> pour initialiser le labyrinthe pass� en 
	 * param�tre en fonction du fichier de configuration pass� en param�tre
	 */
	friend istream& operator>>(istream &config, Labyrinthe &labyrinthe);

	/*
	 * M�thode qui retourne la hauteur du labyrinthe
	 */
	int getHauteurLabyrinthe();

	/*
	 * M�thode qui retourne la largeur du labyrinthe
	 */
	int getLargeurLabyrinthe();

	/*
	 * M�thode qui retourne la hauteur maximum possible pour �viter au Pac-Man de sortir du labyrinthe
	 */
	int getHauteurLabyrintheMax();

	/*
	 * M�thode qui retourne la largeur maximum possible pour �viter au Pac-Man de sortir du labyrinthe
	 */
	int getLargeurLabyrintheMax();

	/*
	 * M�thode qui retourne la propri�t�e d1 de la viewport du Jeu
	 */
	double getD1();

	/*
	 * M�thode qui retourne la propri�t�e d2 de la viewport du Jeu
	 */
	double getD2();

	/*
	 * M�thode qui retourne la propri�t�e delta1 de la viewport du Jeu
	 */
	double getDelta1();

	/*
	 * M�thode qui retourne la propri�t�e delta2 de la viewport du Jeu
	 */
	double getDelta2();

	/*
	 * M�thode qui retourne la forme contenue dans le tableau des murs � l'indice x et y pass� en param�tre
	 */
	int getMur(int x, int y);

	/*
	 * M�thode qui retourne le type d'�l�ment contenu dans le tableau des pastilles 
	 * � l'indice x et y pass� en param�tre
	 */
	int getPastille(int x, int y);

	/*
	 * M�thode qui modifie le type d'�l�ment contenu dans le tableau des pastilles 
	 * � l'indice x et y pass� en param�tre (2=super pastille, 1=pastille, 0=pas de pastille, 
	 * -1=emplacement vide anciennement occup� par une pastille, -2=emplacement vide anciennement 
	 * occup� par une super pastille)
	 */
	void setPastille(int x, int y, int valeur);

	/*
	 * M�thode qui retourne true si le labyrinthe est ouvert � l'indice x et y pass� en param�tre, false sinon
	 */
	bool isOuvert(double y, double x);

	/*
	 * M�thode qui retourne le nombre de pastilles total dans le labyrinthe
	 */
	int getNbPastillesTotal();

	/*
	 * M�thode qui retourne le nombres de pastilles restantes dans le labyrinthe
	 */
	int getNbPastillesRestantes();

	/*
	 * M�thode qui modifie le nombres de pastilles restantes en fonction du nouveau 
	 * nombre de pastilles restantes pass� en param�tre
	 */
	void setNbPastillesRestantes(int nbPastilles);

	/*
	 * M�thode qui d�cr�mente le nombres de pastilles restantes
	 */
	void decNbPastillesRestantes();

	/*
	 * M�thode qui renvoie true si le labyrinthe est en rotation, false sinon
	 */
	bool isRotating();

	/*
	 * M�thode qui modifie la rotation du labyrinthe (la d�marre ou la stoppe)
	 */
	void setRotating(bool rotate);
};
