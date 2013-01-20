#include "Mur.h"

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Mur *Mur::instance = 0;

/*
 * Constructeur (Pattern Singleton)
 */
Mur::Mur(void)
{
	mur = 0;
	init();
}

/*
 * Destructeur
 */
Mur::~Mur(void)
{
	glDeleteLists(mur, 1);
}

/*
 * Méthode qui retourne l'instance du modèle (Pattern Singleton) sous forme de pointeur
 */
Mur *Mur::getInstance() {
	if (instance == 0)
		instance = new Mur();

	return instance;
}

/*
 * Méthode qui initialise les displays lists
 */
void Mur::init() {
	mur = glGenLists(1);

	glNewList(mur, GL_COMPILE);
		mur3D();
	glEndList();
}

/*
 * Méthode qui contient les instructions OpenGL pour la display list du mur nord en 3D
 */
void Mur::mur3D() {
	creerCube(-0.5, 0.5, 0.5, 0.6, -0.5, 0.5, 16);
}

/*
 * Méthode qui crée un cube en 3D avec tesselation (c.à.d. cube subdivisé en plusieurs faces) pour permette un plus bel éclairage, on lui passe en paramètre les
 * coordonnées du cube à créer et le nombres de tranches
 */
void Mur::creerCube(double x1, double x2, double y1, double y2, double z1, double z2, int slices) {
    glBegin(GL_QUADS);

    double xs = (x2 - x1) / slices;
    double ys = (y2 - y1) / slices;
    double zs = (z2 - z1) / slices;

    for(int j = 0; j < slices; ++j) {
        for(int i = 0; i < slices; ++i) {
            double xi1 = x1 + xs * i;
            double xi2 = xi1 + xs;
            double yi1 = y1 + ys * i;
            double yi2 = yi1 + ys;
            double yj1 = y1 + ys * j;
            double yj2 = yj1 + ys;
            double zj1 = z1 + zs * j;
            double zj2 = zj1 + zs;

            // Front
            glNormal3f(0.0, -1.0,  0.0);
            glVertex3d(xi1,  y1, zj2);
            glVertex3d(xi1,  y1, zj1);
            glVertex3d(xi2,  y1, zj1);
            glVertex3d(xi2,  y1, zj2);

            // Top
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3d(xi1, yj1, z2);
            glVertex3d(xi1, yj2, z2);
            glVertex3d(xi2, yj2, z2);
            glVertex3d(xi2, yi1, z2);

            // Left
            glNormal3f(-1.0,  0.0, 0.0);
            glVertex3d(x1, yi1, zj2);
            glVertex3d(x1, yi2, zj2);
            glVertex3d(x1, yi2, zj1);
            glVertex3d(x1, yi1, zj1);

            // Bottom
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3d(xi1, yj1, z1);
            glVertex3d(xi1, yj2, z1);
            glVertex3d(xi2, yj2, z1);
            glVertex3d(xi2, yj1, z1);

            // Right
            glNormal3f(1.0, 0.0, 0.0);
            glVertex3d(x2, yi1, zj2);
            glVertex3d(x2, yi2, zj2);
            glVertex3d(x2, yi2, zj1);
            glVertex3d(x2, yi1, zj1);

            // Back
            glNormal3f(0.0, 1.0,  0.0);
            glVertex3d(xi1, y2, zj2);
            glVertex3d(xi1, y2, zj1);
            glVertex3d(xi2, y2, zj1);
            glVertex3d(xi2, y2, zj2);
        }
    }
    glEnd();
}

/*
 * Méthode qui dessine un mur Nord en 2D
 */
void Mur::dessinerMurNord2D() {
	glBegin(GL_LINES);
		glVertex2d(-0.5, 0.5);
		glVertex2d(0.5, 0.5);
	glEnd();
}

/*
 * Méthode qui dessine un mur Nord-Ouest en 2D
 */
void Mur::dessinerMurNordOuest2D() {
	glBegin(GL_LINES);
		glVertex2d(-0.5, 0.5);
		glVertex2d(0.5, 0.5);
		glVertex2d(-0.5, 0.5);
		glVertex2d(-0.5, -0.5);
	glEnd();
}

/*
 * Méthode qui dessine un mur Est et un mur Ouest en 2D
 */
void Mur::dessinerMurEstOuest2D() {
	glBegin(GL_LINES);
		glVertex2d(-0.5, 0.5);
		glVertex2d(-0.5, -0.5);
		glVertex2d(0.5, 0.5);
		glVertex2d(0.5, -0.5);
	glEnd();
}

/*
 * Méthode qui dessine un mur Nord en 3D
 */
void Mur::dessinerMurNord3D() {
	glCallList(mur);
}

/*
 * Méthode qui dessine un mur Nord-Ouest en 3D
 */
void Mur::dessinerMurNordOuest3D() {
	dessinerMurNord3D();
    glRotatef(90., 0, 0, 1);
	dessinerMurNord3D();
    glRotatef(-90, 0, 0, 1);
}

/*
 * Méthode qui dessine un mur Est et un mur Ouest en 3D
 */
void Mur::dessinerMurEstOuest3D() {
	glRotatef(-90., 0, 0, 1);
	dessinerMurNord3D();
    glRotatef(180, 0, 0, 1);
	dessinerMurNord3D();
    glRotatef(-90, 0, 0, 1);
}
