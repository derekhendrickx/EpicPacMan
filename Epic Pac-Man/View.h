#pragma once

#include "Utils.h"

#include "Model.h"
#include "Dessin.h"
#include "UI.h"
#include "Camera.h"

class View {
public:
	/* 
	 * Méthode qui définit le modèle pour affichage à l'écran
	 */
	virtual void display() = 0;
	/*
	 * Méthode appelé en cas de redimensionnement de la fenêtre d'écran
	 */
	virtual void reshape(int w, int h) = 0;
	/*
	 * Méthode qui rafraichit l'affichage
	 */
	virtual void redraw() = 0;
	/*
	 * Méthode qui retourne un double représentant le d1 de la viewport des contrôles
	 */
	virtual double getD1Controles() = 0;
	/*
	 * Méthode qui retourne un double représentant le d2 de la viewport des contrôles
	 */
	virtual double getD2Controles() = 0;
	/*
	 * Méthode qui retourne un double représentant le delta1 de la viewport des contrôles
	 */
	virtual double getDelta1Controles() = 0;
	/*
	 * Méthode qui retourne un double représentant le delda2 de la viewport des contrôles
	 */
	virtual double getDelta2Controles() = 0;
	/*
	 * Méthode qui retourne un entier représentant le w global
	 */
	virtual int getWGlobal() = 0;
	/*
	 * Méthode qui retourne un entier représentant le h global
	 */
	virtual int getHGlobal() = 0;
	/*
	 * Méthode qui retourne un entier représentant la coordonnées 
	 * Y du coin inférieur gauche de la viewport de jeu
	 */
	virtual int getYCoinInferieurGaucheViewportJeu() = 0;
	/*
	 * Méthode qui retourne un entier représentant la largeur de la viewport de jeu
	 */
	virtual int getLargeurViewportJeu() = 0;
	/*
	 * Méthode qui retourne un entier représentant la hauteur de la viewport de jeu
	 */
	virtual int getHauteurViewportJeu() = 0;
	/*
	 * Méthode qui gère la projection de la viewport de jeu
	 */
	virtual void projectionViewportJeu() = 0;
};
