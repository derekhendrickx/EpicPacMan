#pragma once

#include "Utils.h"
#include "Fleche.h"
#include "Bouton.h"
#include "Texte.h"

class UI
{
private:
	// Attibut qui retient l'instance de la Fleche
	Fleche *fleche;
	// Attibut qui retient l'instance du Bouton
	Bouton *bouton;
	// Attibut qui retient l'instance du Texte
	Texte *texte;
	/*
	 * Méthode qui affiche le bouton pour passer en 2D
	 */
	void vue2D();
	/*
	 * Méthode qui affiche le bouton pour passer en 3D parallèle
	 */
	void parallele();
	/*
	 * Méthode qui affiche le bouton pour passer en 3D perspective
	 */
	void perspective();
	/*
	 * Méthode qui affiche le bouton pour rejouer
	 */
	void rejouer();
	/*
	 * Méthode qui affiche le bouton pour quitter
	 */
	void quitter();
	/*
	 * Méthode qui affiche le bouton pour zoomer en avant
	 */
	void zoomPlus();
	/*
	 * Méthode qui affiche le bouton pour zoomer en arrière
	 */
	void zoomMoins();
public:
	/*
	 * Constructeur
	 */
	UI(void);
	/*
	 * Destructeur
	 */
	~UI(void);
	/*
	 * Méthode qui affiche les différents informations sur la partie et le Pac-Man pour la 2D
	 */
	void affichageInfos();
	/*
	 * Méthode qui dessine dessine les boutons pour la 2D
	 */
	void dessinerBoutons();
	/*
	 * Méthode qui dessine les contrôles pour la souris pour la 2D
	 */
	void dessinerFlechesDeControle();
};

