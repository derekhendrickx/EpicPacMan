#include "Camera.h"

// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
Camera *Camera::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Camera::Camera()
{
	// Facteur de zoom neutre (par défaut)
	facteurZoom = 1.0;
	angleDeRotation = 0.0;
}

/*
 * Destructeur
 */
Camera::~Camera()
{
	// Vide car pattern singleton
}

/*
 * Méthode qui retourne de l'instance de la classe (Pattern Singleton) sous forme de pointeur
 */
Camera *Camera::getInstance() {
	if (instance == 0)
		instance = new Camera();

	return instance;
}

/*
 * Méthode qui retourne un double contenant le facteur de zoom
 */
double Camera::getFacteurZoom() {
	return facteurZoom;
}

/*
 * Méthode qui change la valeur du facteur de zoom par une nouvelle passée en paramètre
 */
void Camera::setFacteurZoom(double fZoom) {
	facteurZoom = fZoom;
}

/*
 * Méthode qui gère le zoom en avant en 3D parallèle
 */
void Camera::zoomer3D() {
	if (facteurZoom > ZOOM_MAX_3D) {
		facteurZoom -= PAS_ZOOM;
	}
}

/*
 * Méthode qui gère le zoom en avant en 3D perspective
 */
void Camera::zoomer3DPerspective() {
	if (facteurZoom > ZOOM_MAX_3DPERSPECTIVE) {
		facteurZoom -= PAS_ZOOM;
	}
}

/*
 * Méthode qui gère le zoom en arrière en 3D parallèle
 */
void Camera::dezoomer3D() {
	if (facteurZoom < ZOOM_MIN_3D) {
		facteurZoom += PAS_ZOOM;
	}
}

/*
 * Méthode qui gère le zoom en arrière en 3D perspective
 */
void Camera::dezoomer3DPerspective() {
	if (facteurZoom < ZOOM_MIN_3DPERSPECTIVE) {
		facteurZoom += PAS_ZOOM;
	}
}

/*
 * Méthode qui renvoie l'angle de rotation du labyrinthe
 */
double Camera::getAngleDeRotation() {
	return angleDeRotation;
}

/*
 * Méthode qui incrémente l'angle de rotation du labyrinthe
 */
void Camera::incAngleDeRotation() {
	if (angleDeRotation < 360.0) {
		angleDeRotation += PAS_ROTATION;
	} else {
		angleDeRotation = 0.0;
	}
}
