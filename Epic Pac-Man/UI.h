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
	 * M�thode qui affiche le bouton pour passer en 2D
	 */
	void vue2D();
	/*
	 * M�thode qui affiche le bouton pour passer en 3D parall�le
	 */
	void parallele();
	/*
	 * M�thode qui affiche le bouton pour passer en 3D perspective
	 */
	void perspective();
	/*
	 * M�thode qui affiche le bouton pour rejouer
	 */
	void rejouer();
	/*
	 * M�thode qui affiche le bouton pour quitter
	 */
	void quitter();
	/*
	 * M�thode qui affiche le bouton pour zoomer en avant
	 */
	void zoomPlus();
	/*
	 * M�thode qui affiche le bouton pour zoomer en arri�re
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
	 * M�thode qui affiche les diff�rents informations sur la partie et le Pac-Man pour la 2D
	 */
	void affichageInfos();
	/*
	 * M�thode qui dessine dessine les boutons pour la 2D
	 */
	void dessinerBoutons();
	/*
	 * M�thode qui dessine les contr�les pour la souris pour la 2D
	 */
	void dessinerFlechesDeControle();
};

