#include "Model.h"

using namespace std;

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Model *Model::instance = 0;

/*
 * Constructeur qui initialise une Quadric, une instance de Pac-Man,
 * le niveau � 1, le score � 0 et initialise le labyrinthe (Pattern Singleton)
 */
Model::Model() {
	pacman = PacManModel::getInstance();
	fantome = FantomeModel::getInstance();

	labyrinthe = new Labyrinthe();
	niveau = 1;
	score = 0;

	// Initialisation du labyrinthe
	initLabyrinthe(recupererFichierConfig());
}

/*
 * Destructeur
 */
Model::~Model() {
	delete labyrinthe;
}

/*
 * M�thode qui retourne l'instance du mod�le (Pattern Singleton) sous forme de pointeur
 */
Model *Model::getInstance() {
	if (instance == 0)
		instance = new Model();

	return instance;
}

/*
 * M�thode qui retourne une string contenant le nom de fichier de configuration du labyrinthe
 */
string Model::recupererFichierConfig() {
	std::ostringstream oss;
	oss << niveau;
	string fichier = FICHIER_CONFIG;

	return fichier + oss.str() + EXTENTION_FICHIER_CONFIG;
}

/*
 * M�thode qui charge un labyrinthe � partir d'un fichier
 */
void Model::initLabyrinthe(string fichierConfig) {
	ifstream fichier(fichierConfig.c_str());
	fichier >> *labyrinthe;
}

/*
 * M�thode qui retourne l'instance du Pac-Man sous forme de pointeur
 */
PacManModel *Model::getPacman() {
	return pacman;
}

/*
* M�thode qui retourne l'instance du Fant�me sous forme de pointeur
*/
FantomeModel *Model::getFantome() {
	return fantome;
}

/*
 * M�thode qui retourne l'instance du Labyrinthe sous forme de pointeur
 */
Labyrinthe *Model::getLabyrinthe() {
	return labyrinthe;
}

/*
 * M�thode qui retourne le niveau de progression dans le jeu
 */
int Model::getNiveau() {
	return niveau;
}

/*
 * M�thode qui modifie le niveau de progression dans le jeu
 */
void Model::setNiveau(int nouveauNiveau) {
	niveau = nouveauNiveau;
}

/*
 * M�thode qui incr�mente le niveau de progression dans le jeu 
 * en fonction du nouveau niveau pass� en param�tre
 */
void Model::incNiveau(int lvl) {
	niveau += lvl;
}

/*
 * M�thode qui retourne le score courant
 */
int Model::getScore() {
	return score;
}

/*
 * M�thode qui incr�mente le score en fonction du pas pass� en param�tre
 */
void Model::incScore(int pas) {
	score += pas;
}

/*
 * M�thode qui modifie le score en fonction d'un nouveau score pass� en param�tre
 */
void Model::setScore(int newScore) {
	score = 0;
}

/*
 * M�thode qui permet de g�rer le changement de niveau, un changement de niveau
 * implique un changement de labyrinthe.
 * return true s'il est possible de changer de niveau, false sinon.
 */
bool Model::chargerNiveau(int niveauACharger) {
	if (niveauACharger > 0 && niveauACharger <= NB_NIVEAUX) {
		niveau = niveauACharger;
		delete(labyrinthe);
		labyrinthe = new Labyrinthe();
		initLabyrinthe(recupererFichierConfig());

		return true;
	} 

	return false;
}
