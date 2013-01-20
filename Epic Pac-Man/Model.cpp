#include "Model.h"

using namespace std;

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Model *Model::instance = 0;

/*
 * Constructeur qui initialise une Quadric, une instance de Pac-Man,
 * le niveau à 1, le score à 0 et initialise le labyrinthe (Pattern Singleton)
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
 * Méthode qui retourne l'instance du modèle (Pattern Singleton) sous forme de pointeur
 */
Model *Model::getInstance() {
	if (instance == 0)
		instance = new Model();

	return instance;
}

/*
 * Méthode qui retourne une string contenant le nom de fichier de configuration du labyrinthe
 */
string Model::recupererFichierConfig() {
	std::ostringstream oss;
	oss << niveau;
	string fichier = FICHIER_CONFIG;

	return fichier + oss.str() + EXTENTION_FICHIER_CONFIG;
}

/*
 * Méthode qui charge un labyrinthe à partir d'un fichier
 */
void Model::initLabyrinthe(string fichierConfig) {
	ifstream fichier(fichierConfig.c_str());
	fichier >> *labyrinthe;
}

/*
 * Méthode qui retourne l'instance du Pac-Man sous forme de pointeur
 */
PacManModel *Model::getPacman() {
	return pacman;
}

/*
* Méthode qui retourne l'instance du Fantôme sous forme de pointeur
*/
FantomeModel *Model::getFantome() {
	return fantome;
}

/*
 * Méthode qui retourne l'instance du Labyrinthe sous forme de pointeur
 */
Labyrinthe *Model::getLabyrinthe() {
	return labyrinthe;
}

/*
 * Méthode qui retourne le niveau de progression dans le jeu
 */
int Model::getNiveau() {
	return niveau;
}

/*
 * Méthode qui modifie le niveau de progression dans le jeu
 */
void Model::setNiveau(int nouveauNiveau) {
	niveau = nouveauNiveau;
}

/*
 * Méthode qui incrémente le niveau de progression dans le jeu 
 * en fonction du nouveau niveau passé en paramètre
 */
void Model::incNiveau(int lvl) {
	niveau += lvl;
}

/*
 * Méthode qui retourne le score courant
 */
int Model::getScore() {
	return score;
}

/*
 * Méthode qui incrémente le score en fonction du pas passé en paramètre
 */
void Model::incScore(int pas) {
	score += pas;
}

/*
 * Méthode qui modifie le score en fonction d'un nouveau score passé en paramètre
 */
void Model::setScore(int newScore) {
	score = 0;
}

/*
 * Méthode qui permet de gérer le changement de niveau, un changement de niveau
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
