#pragma once

#include "Model.h"
#include "Mur.h"
#include "Pastille.h"
#include "PacMan.h"
#include "Fantome.h"
#include "Camera.h"

class Dessin {
private:
	// Attibut qui retient l'instance du Model pour accéder aux données modifiables
	Model *model;
	// Attibut qui retient l'instance du Labyrinthe
	Labyrinthe *labyrinthe;
	// Attibut qui retient l'instance du Mur
	Mur *mur;
	// Attibut qui retient l'instance de la Pastille
	Pastille *pastille;
	// Attibut qui retient l'instance du Pac-Man
	PacMan *pacman;
	// Attibut qui retient l'instance du Fantome
	Fantome *fantome;
	// Attribut qui retient l'instance de la caméra
	Camera *camera;

public:
	/*
	 * Constructeur (Pattern Singleton)
	 */
	Dessin(void);
	/*
	 * Destructeur
	 */
	~Dessin(void);
	/*
	 * Méthode qui dessine le jeu en 2D
	 */
	void dessinerJeu2D();
	/*
	 * Méthode qui dessine le labyrinthe en 2D
	 */
	void dessinerLabyrinthe2D();
	/*
	 * Méthode qui dessine les pastilles en 2D
	 */
	void dessinerContenuLabyrinthe2D();
	/*
	 * Méthode qui dessine le Pac-Man en 2D
	 */
	void dessinerPacman2D();
	/*
	 * Méthode qui dessine le Fantôme en 2D
	 */
	void dessinerFantome2D();
	/*
	 * Méthode qui dessine le jeu en 3D
	 */
	void dessinerJeu3D();
	/*
	 * Méthode qui dessine le labyrinthe en 3D
	 */
	void dessinerLabyrinthe3D();
	/*
	 * Méthode qui dessine les pastilles en 3D
	 */
	void dessinerContenuLabyrinthe3D();
	/*
	 * Méthode qui dessine le Pac-Man en 3D
	 */
	void dessinerPacman3D();
	/*
	 * Méthode qui dessine le Fantôme en 3D
	 */
	void dessinerFantome3D();
};
