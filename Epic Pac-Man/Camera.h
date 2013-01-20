#pragma once

#include "Utils.h"

class Camera {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Camera *instance;
	// Attribut qui retient le zoom à appliquer au labyrinthe
	double facteurZoom;
	// Attribut qui retient l'angle de rotation à appliquer au labyrinthe
	double angleDeRotation;

	/*
	 * Constructeur (Pattern Singleton)
	 */
	Camera();
public:
	/*
	 * Destructeur
	 */
	~Camera();
	/*
	 * Méthode qui retourne de l'instance de la classe (Pattern Singleton) sous forme de pointeur
	 */
	static Camera *getInstance();

	/*
	 * Méthode qui retourne un double contenant le facteur de zoom
	 */
	double getFacteurZoom();
	/*
	 * Méthode qui change la valeur du facteur de zoom par une nouvelle passée en paramètre
	 */
	void setFacteurZoom(double fZoom);
	/*
	 * Méthode qui gère le zoom en avant en 3D parallèle
	 */
	void zoomer3D();
	/*
	 * Méthode qui gère le zoom en avant en 3D perspective
	 */
	void zoomer3DPerspective();
	/*
	 * Méthode qui gère le zoom en arrière en 3D parallèle
	 */
	void dezoomer3D();
	/*
	 * Méthode qui gère le zoom en arrière en 3D perspective
	 */
	void dezoomer3DPerspective();
	/*
	 * Méthode qui renvoie l'angle de rotation du labyrinthe
	 */
	double getAngleDeRotation();
	/*
	 * Méthode qui incrémente l'angle de rotation du labyrinthe
	 */
	void incAngleDeRotation();
};

