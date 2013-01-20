#include "Utils.h"

// Caractéristiques de la lumière
float Utils::LightDifBlanc[4] = {0.9f, 0.9f, 0.9f, 1.0f};
float Utils::LightSpecBlanc[4] = {0.0f, 0.0f, 0.0f, 1.0f};
float Utils::LightAmbBlanc[4] = {0.5f, 0.5f, 0.5f, 1.0f};
float Utils::LightNoir[4] = {0.0f, 0.0f, 0.0f, 1.0f};

// Position et direction du Spot
float Utils::Spot1Dir[3] = {0.0f, 0.0f, -1.0f};
float Utils::Spot1Pos[3] = {0.f, 0.0f, 4.0f};

// Positions des lumières
float Utils::Light1Pos[4] = {-4.0f, 6.0f, 0.0f, 0.0f};
float Utils::Light2Pos[4] = {0.0f, 6.0f, 0.0f, 0.0f};

// Matériel blanc
float Utils::SpecBlanc[4] = {1.0f, 1.0f, 1.0f, 1.0f};
float Utils::DifBlanc[4] = {0.8f, 0.8f, 0.8f, 1.0f};
float Utils::AmbBlanc[4] = {0.74f, 0.74f, 0.74f, 1.0f};

// Matériel bleu
float Utils::SpecBleu[4] = {0.0f, 0.2f, 0.6f, 1.0f};
float Utils::DifBleu[4] = {0.06f, 0.26f, 0.66f, 1.0f};
float Utils::AmbBleu[4] = {0.2f, 0.4f, 0.8f, 1.0f};

// Matériel jaune
float Utils::SpecJaune[4] = {1.0f, 1.0f, 0.0f, 1.0f};
float Utils::DifJaune[4] = {1.0f, 0.8f, 0.0f, 1.0f};
float Utils::AmbJaune[4] = {1.0f, 0.8f, 0.2f, 1.0f};

// Matériel rouge
float Utils::SpecRouge[4] = {1.0f, 0.0f, 0.0f, 1.0f};
float Utils::DifRouge[4] = {1.0f, 0.2f, 0.2f, 1.0f};
float Utils::AmbRouge[4] = {0.8f, 0.0f, 0.0f, 1.0f};

/*
 * Méthode qui retourne un boolean, true si le double passer en paramètre est un entier sinon false
 */
bool Utils::isEntier(double val) {
	return val == (int) val;
}

/*
 * Méthode qui retourne un boolean, true si la coordonnée composée de deux double est entière sinon false
 */
bool Utils::isCoordEntiere(double coordX, double coordY) {
	return isEntier(coordX) && isEntier(coordY);
}

/*
 * Méthode qui retourne un double calculant l'arrondis à deux décimales du double passé en paramètre
 */
double Utils::arrondiDeuxDecimale(double val) {
	return floor((val + 0.005) * 100) / 100.0;
}
