#pragma once

#include <string>

#include "MyGlut.h"

#define BUFSIZE 512

// D�finition des diff�rentes orientations possibles pour le Pac-man et le fant�me
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

// Path du fichier de configuration du jeu
#define FICHIER_CONFIG "Config/Labyrinthe_"
#define EXTENTION_FICHIER_CONFIG ".txt"

// Nombre de niveaux
#define NB_NIVEAUX 3

// Constantes de dessin
#define TAILLE_PASTILLE 0.1
#define TAILLE_SUPER_PASTILLE 0.15

// Buffer pour les textes
#define TAILLE_STR 256

// Constantes du Pac-Man
#define TAILLE_PACMAN 0.4
// Nombre de pas maximum avant de quitter le mode Super
#define NB_PAS_MAX 5
// Fluidit� (vitesse) du Pac-Man
#define PAS 0.05
// Pas utilis� pour calculer la position finale sans fluidit�
#define PAS_NORMAL 1

// Temps de caden�age du rafraichissement de l'image
#define TEMPSBASE 60
// Temps de caden�age du d�placement du Pac-Man et du Fant�me (vitesse)
#define VITESSE 15
// Temps de caden�age de l'ouverture/fermeture de la bouche du Pac-Man
#define BOUCHE 100
// Temps durant lequel le pacman est en mode super et la fant�me est vuln�rable
#define TEMPSSUPER 4000
// Valeur ASCI de la barre d'espace du clavier
#define SPACEBAR 32

// Zoom
#define PAS_ZOOM 0.02
// Zoom MAX en 3D parall�le
#define ZOOM_MAX_3D 0.96
// Zoom MIN en 3D parall�le
#define ZOOM_MIN_3D 2.64
// Zoom MAX en 3D perspective
#define ZOOM_MAX_3DPERSPECTIVE 1.0
// Zoom MIN en 3D perspective
#define ZOOM_MIN_3DPERSPECTIVE 1.26

// Rotation du labyrinthe
#define PAS_ROTATION 1.0

using namespace glut;
using namespace std;

class Utils
{
public:
	// Caract�ristiques de la lumi�re
	static float LightDifBlanc[4];
	static float LightSpecBlanc[4];
	static float LightAmbBlanc[4];
	static float LightNoir[4];

	// Position et direction du Spot
	static float Spot1Dir[3];
	static float Spot1Pos[3];

	// Positions des lumi�res
	static float Light1Pos[4];
	static float Light2Pos[4];

	// Mat�riel blanc
	static float SpecBlanc[4];
	static float DifBlanc[4];
	static float AmbBlanc[4];

	// Mat�riel bleu
	static float SpecBleu[4];
	static float DifBleu[4];
	static float AmbBleu[4];

	// Mat�riel jaune
	static float SpecJaune[4];
	static float DifJaune[4];
	static float AmbJaune[4];

	// Mat�riel rouge
	static float SpecRouge[4];
	static float DifRouge[4];
	static float AmbRouge[4];

	/*
	 * M�thode qui retourne un boolean, true si le double passer en param�tre est un entier sinon false
	 */
	static bool isEntier(double val);

	/*
	 * M�thode qui retourne un boolean, true si la coordonn�e compos�e de deux double est enti�re sinon false
	 */
	static bool isCoordEntiere(double coordX, double coordY);

	/*
	 * M�thode qui retourne un double calculant l'arrondis � deux d�cimales du double pass� en param�tre
	 */
	static double arrondiDeuxDecimale(double val);
};
