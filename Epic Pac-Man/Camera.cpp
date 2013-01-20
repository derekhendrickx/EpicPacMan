#include "Camera.h"

// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
Camera *Camera::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Camera::Camera()
{
	// Facteur de zoom neutre (par d�faut)
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
 * M�thode qui retourne de l'instance de la classe (Pattern Singleton) sous forme de pointeur
 */
Camera *Camera::getInstance() {
	if (instance == 0)
		instance = new Camera();

	return instance;
}

/*
 * M�thode qui retourne un double contenant le facteur de zoom
 */
double Camera::getFacteurZoom() {
	return facteurZoom;
}

/*
 * M�thode qui change la valeur du facteur de zoom par une nouvelle pass�e en param�tre
 */
void Camera::setFacteurZoom(double fZoom) {
	facteurZoom = fZoom;
}

/*
 * M�thode qui g�re le zoom en avant en 3D parall�le
 */
void Camera::zoomer3D() {
	if (facteurZoom > ZOOM_MAX_3D) {
		facteurZoom -= PAS_ZOOM;
	}
}

/*
 * M�thode qui g�re le zoom en avant en 3D perspective
 */
void Camera::zoomer3DPerspective() {
	if (facteurZoom > ZOOM_MAX_3DPERSPECTIVE) {
		facteurZoom -= PAS_ZOOM;
	}
}

/*
 * M�thode qui g�re le zoom en arri�re en 3D parall�le
 */
void Camera::dezoomer3D() {
	if (facteurZoom < ZOOM_MIN_3D) {
		facteurZoom += PAS_ZOOM;
	}
}

/*
 * M�thode qui g�re le zoom en arri�re en 3D perspective
 */
void Camera::dezoomer3DPerspective() {
	if (facteurZoom < ZOOM_MIN_3DPERSPECTIVE) {
		facteurZoom += PAS_ZOOM;
	}
}

/*
 * M�thode qui renvoie l'angle de rotation du labyrinthe
 */
double Camera::getAngleDeRotation() {
	return angleDeRotation;
}

/*
 * M�thode qui incr�mente l'angle de rotation du labyrinthe
 */
void Camera::incAngleDeRotation() {
	if (angleDeRotation < 360.0) {
		angleDeRotation += PAS_ROTATION;
	} else {
		angleDeRotation = 0.0;
	}
}
