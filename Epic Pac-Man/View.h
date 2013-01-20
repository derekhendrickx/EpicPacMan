#pragma once

#include "Utils.h"

#include "Model.h"
#include "Dessin.h"
#include "UI.h"
#include "Camera.h"

class View {
public:
	/* 
	 * M�thode qui d�finit le mod�le pour affichage � l'�cran
	 */
	virtual void display() = 0;
	/*
	 * M�thode appel� en cas de redimensionnement de la fen�tre d'�cran
	 */
	virtual void reshape(int w, int h) = 0;
	/*
	 * M�thode qui rafraichit l'affichage
	 */
	virtual void redraw() = 0;
	/*
	 * M�thode qui retourne un double repr�sentant le d1 de la viewport des contr�les
	 */
	virtual double getD1Controles() = 0;
	/*
	 * M�thode qui retourne un double repr�sentant le d2 de la viewport des contr�les
	 */
	virtual double getD2Controles() = 0;
	/*
	 * M�thode qui retourne un double repr�sentant le delta1 de la viewport des contr�les
	 */
	virtual double getDelta1Controles() = 0;
	/*
	 * M�thode qui retourne un double repr�sentant le delda2 de la viewport des contr�les
	 */
	virtual double getDelta2Controles() = 0;
	/*
	 * M�thode qui retourne un entier repr�sentant le w global
	 */
	virtual int getWGlobal() = 0;
	/*
	 * M�thode qui retourne un entier repr�sentant le h global
	 */
	virtual int getHGlobal() = 0;
	/*
	 * M�thode qui retourne un entier repr�sentant la coordonn�es 
	 * Y du coin inf�rieur gauche de la viewport de jeu
	 */
	virtual int getYCoinInferieurGaucheViewportJeu() = 0;
	/*
	 * M�thode qui retourne un entier repr�sentant la largeur de la viewport de jeu
	 */
	virtual int getLargeurViewportJeu() = 0;
	/*
	 * M�thode qui retourne un entier repr�sentant la hauteur de la viewport de jeu
	 */
	virtual int getHauteurViewportJeu() = 0;
	/*
	 * M�thode qui g�re la projection de la viewport de jeu
	 */
	virtual void projectionViewportJeu() = 0;
};
