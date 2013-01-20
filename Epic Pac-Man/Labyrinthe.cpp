#include "Labyrinthe.h"

/*
 * Constructeur
 */
Labyrinthe::Labyrinthe() {
	rotating = false;
}

/*
 * Destructeur qui lib�re la m�moire occup�e par le labyrinthe et les pastilles
 */
Labyrinthe::~Labyrinthe() {
	for(int i(0); i < hauteurLabyrinthe ; i++)
		delete[] murs[i];
	delete[] murs;

	for(int i(0); i < hauteurLabyrinthe ; i++)
		delete[] pastilles[i];
	delete[] pastilles;
}

/*
 * M�thode qui surcharge l'op�rateur >> pour initialiser le labyrinthe pass� en 
 * param�tre en fonction du fichier de configuration pass� en param�tre
 */
istream& operator>>(istream &config, Labyrinthe &labyrinthe) {
	int x, y, pastille, nbPastille = 0;
	PacManModel *pacman = PacManModel::getInstance();
	FantomeModel *fantome = FantomeModel::getInstance();

	if(config) {
		config >> labyrinthe.hauteurLabyrinthe;
		config >> labyrinthe.largeurLabyrinthe;

		config >> labyrinthe.d1;
		config >> labyrinthe.d2;
		config >> labyrinthe.delta1;
		config >> labyrinthe.delta2;

		// Initialisation des formes du labyrinthe
		labyrinthe.murs = new int*[labyrinthe.hauteurLabyrinthe];
		for (int i(0); i < labyrinthe.hauteurLabyrinthe; i++) {
			labyrinthe.murs[i] = new int[labyrinthe.largeurLabyrinthe];

			for (int j(0); j < labyrinthe.largeurLabyrinthe; j++) {
				config >> labyrinthe.murs[i][j];
			}
		}

		config >> x;
		config >> y;

		pacman->setPositionXInitiale(x);
		pacman->setPositionYInitiale(y);
		pacman->setPositionX(x);
		pacman->setPositionY(y);

		config >> x;
		config >> y;
		fantome->setPositionXInitiale(x);
		fantome->setPositionYInitiale(y);
		fantome->setPositionX(x);
		fantome->setPositionY(y);

		// Initialisation des pastilles
		labyrinthe.pastilles = new int*[labyrinthe.hauteurLabyrinthe];
		for (int i(0); i < labyrinthe.hauteurLabyrinthe; i++) {
			labyrinthe.pastilles[i] = new int[labyrinthe.largeurLabyrinthe];

			for (int j(0); j < labyrinthe.largeurLabyrinthe; j++) {
				config >> pastille;
				if (pastille > 0) {
					nbPastille++;
				}
				labyrinthe.pastilles[i][j] = pastille;
			}
		}

		labyrinthe.nbPastillesTotal = nbPastille;
		labyrinthe.nbPastillesRestantes = labyrinthe.nbPastillesTotal;
	} else {
		cout << "ERREUR: Impossible d'ouvrir le fichier de configuration en lecture." << endl;
	}

	return config;
}

/*
 * M�thode qui retourne la hauteur du labyrinthe
 */
int Labyrinthe::getHauteurLabyrinthe() {
	return hauteurLabyrinthe;
}

/*
 * M�thode qui retourne la largeur du labyrinthe
 */
int Labyrinthe::getLargeurLabyrinthe() {
	return largeurLabyrinthe;
}

/*
 * M�thode qui retourne la propri�t�e d1 de la viewport du Jeu
 */
double Labyrinthe::getD1() {
	return d1;
}

/*
 * M�thode qui retourne la propri�t�e d2 de la viewport du Jeu
 */
double Labyrinthe::getD2() {
	return d2;
}

/*
 * M�thode qui retourne la propri�t�e delta1 de la viewport du Jeu
 */
double Labyrinthe::getDelta1() {
	return delta1;
}

/*
 * M�thode qui retourne la propri�t�e delta2 de la viewport du Jeu
 */
double Labyrinthe::getDelta2() {
	return delta2;
}

/*
 * M�thode qui retourne la forme contenue dans le tableau des murs � l'indice x et y pass� en param�tre
 */
int Labyrinthe::getMur(int x, int y) {
	return murs[x][y];
}

/*
 * M�thode qui retourne le type d'�l�ment contenu dans le tableau des pastilles 
 * � l'indice x et y pass� en param�tre
 */
int Labyrinthe::getPastille(int x, int y) {
	return pastilles[x][y];
}

/*
 * M�thode qui modifie le type d'�l�ment contenu dans le tableau des pastilles 
 * � l'indice x et y pass� en param�tre (2=super pastille, 1=pastille, 0=pas de pastille, 
 * -1=emplacement vide anciennement occup� par une pastille, -2=emplacement vide anciennement 
 * occup� par une super pastille)
 */
void Labyrinthe::setPastille(int x, int y, int valeur) {
	pastilles[x][y] = valeur;
}

/*
 * M�thode qui retourne true si le labyrinthe est ouvert � l'indice x et y pass� en param�tre, false sinon
 */
bool Labyrinthe::isOuvert(double y, double x) {
	if (murs[(int) x][(int) y] >= 0) {
		return true;
	}
	return false;
}

/*
 * M�thode qui retourne le nombre de pastilles total dans le labyrinthe
 */
int Labyrinthe::getNbPastillesTotal() {
	return nbPastillesTotal;
}

/*
 * M�thode qui retourne le nombres de pastilles restantes dans le labyrinthe
 */
int Labyrinthe::getNbPastillesRestantes() {
	return nbPastillesRestantes;
}

/*
 * M�thode qui modifie le nombres de pastilles restantes en fonction du nouveau 
 * nombre de pastilles restantes pass� en param�tre
 */
void Labyrinthe::setNbPastillesRestantes(int nbPastilles) {
	nbPastillesRestantes = nbPastilles;
}

/*
 * M�thode qui d�cr�mente le nombres de pastilles restantes
 */
void Labyrinthe::decNbPastillesRestantes() {
	nbPastillesRestantes--;
}

/*
 * M�thode qui renvoie true si le labyrinthe est en rotation, false sinon
 */
bool Labyrinthe::isRotating() {
	return rotating;
}

/*
 * M�thode qui modifie la rotation du labyrinthe (la d�marre ou la stoppe)
 */
void Labyrinthe::setRotating(bool rotate) {
	rotating = rotate;
}
