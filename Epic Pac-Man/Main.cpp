#include "Controller.h"


ViewContext *viewContext;

// Chaque call back glut est d�l�gu� � une m�thode de la classe View ou Controller
// Ceci est n�cessaire car glut ne connait que les fonctions C.
void displayCallBack() {
	viewContext->getStrategie()->display();
}

void reshapeCallBack(int width, int height) {
	viewContext->getStrategie()->reshape(width, height);
}

void specialCallBack(int key, int x, int y) {
	Controller::getInstance()->special(key, x, y);
}

void mouseCallBack(int button, int state, int x, int y) {
	Controller::getInstance()->mouse(button, state, x, y);
	Controller::getInstance()->mousePicking(button, state, x, y);
}

void keyboardCallBack(unsigned char key, int x, int y) {
	Controller::getInstance()->keyboard(key, x, y);
}

int main(int argc, char** argv) {
	// Intialisation de glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);		// Initialise les modes li�s � l'affichage
	glutInitWindowSize(800, 600);						// D�finit la taille de la fen�tre d'�cran
	glutInitWindowPosition(100, 100);					// D�finit la position de la fen�tre d'�cran
	glutCreateWindow("Epic Pac-man");					// Cr�e la fen�tre d'�cran avec le nom pass� en argument

	// Sp�cification de la fonction Call back pour le dessin de la vue
	// Cette foncton sera appell�e chaque fois que la vue est redessin�e
	glutDisplayFunc(displayCallBack);

	// Sp�cification de la fonction Call back de redimensionnement de la fen�tre
	// Cette foncton sera appell�e chaque fois que l'utilisateur redimensionne la fen�tre
	glutReshapeFunc(reshapeCallBack);

	// Sp�cification de la fonction Call back de l'appui des touches clavier
	// Cette foncton sera appell�e chaque fois que l'utilisateur appuie sur une touche du clavier
	glutSpecialFunc(specialCallBack);
	
	// Sp�cification de la fonction Call back de la souris
	// Cette foncton sera appell�e chaque fois que l'utilisateur sollicite la souris
    glutMouseFunc(mouseCallBack);

	glutKeyboardFunc(keyboardCallBack);

	if (viewContext == NULL) {
		viewContext = ViewContext::getInstance();
		viewContext->setStrategie(View3DPerspective::getInstance());
	}

	// Le controller est un singleton
	Controller *controller = Controller::getInstance();

	// D�marre une boucle �ternelle d'�coute des call back
	glutMainLoop();
	
	return 0;
}
