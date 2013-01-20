#pragma once

#include "Utils.h"

class Camera {
private:
	// Attibut qui retient un pointeur sur l'instance de la classe (Pattern Singleton)
	static Camera *instance;
	// Attribut qui retient le zoom � appliquer au labyrinthe
	double facteurZoom;
	// Attribut qui retient l'angle de rotation � appliquer au labyrinthe
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
	 * M�thode qui retourne de l'instance de la classe (Pattern Singleton) sous forme de pointeur
	 */
	static Camera *getInstance();

	/*
	 * M�thode qui retourne un double contenant le facteur de zoom
	 */
	double getFacteurZoom();
	/*
	 * M�thode qui change la valeur du facteur de zoom par une nouvelle pass�e en param�tre
	 */
	void setFacteurZoom(double fZoom);
	/*
	 * M�thode qui g�re le zoom en avant en 3D parall�le
	 */
	void zoomer3D();
	/*
	 * M�thode qui g�re le zoom en avant en 3D perspective
	 */
	void zoomer3DPerspective();
	/*
	 * M�thode qui g�re le zoom en arri�re en 3D parall�le
	 */
	void dezoomer3D();
	/*
	 * M�thode qui g�re le zoom en arri�re en 3D perspective
	 */
	void dezoomer3DPerspective();
	/*
	 * M�thode qui renvoie l'angle de rotation du labyrinthe
	 */
	double getAngleDeRotation();
	/*
	 * M�thode qui incr�mente l'angle de rotation du labyrinthe
	 */
	void incAngleDeRotation();
};

