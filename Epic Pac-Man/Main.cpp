#include "Controller.h"


ViewContext *viewContext;

// Chaque call back glut est délégué à une méthode de la classe View ou Controller
// Ceci est nécessaire car glut ne connait que les fonctions C.
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);		// Initialise les modes liés à l'affichage
	glutInitWindowSize(800, 600);						// Définit la taille de la fenêtre d'écran
	glutInitWindowPosition(100, 100);					// Définit la position de la fenêtre d'écran
	glutCreateWindow("Epic Pac-man");					// Crée la fenêtre d'écran avec le nom passé en argument

	// Spécification de la fonction Call back pour le dessin de la vue
	// Cette foncton sera appellée chaque fois que la vue est redessinée
	glutDisplayFunc(displayCallBack);

	// Spécification de la fonction Call back de redimensionnement de la fenêtre
	// Cette foncton sera appellée chaque fois que l'utilisateur redimensionne la fenêtre
	glutReshapeFunc(reshapeCallBack);

	// Spécification de la fonction Call back de l'appui des touches clavier
	// Cette foncton sera appellée chaque fois que l'utilisateur appuie sur une touche du clavier
	glutSpecialFunc(specialCallBack);
	
	// Spécification de la fonction Call back de la souris
	// Cette foncton sera appellée chaque fois que l'utilisateur sollicite la souris
    glutMouseFunc(mouseCallBack);

	glutKeyboardFunc(keyboardCallBack);

	if (viewContext == NULL) {
		viewContext = ViewContext::getInstance();
		viewContext->setStrategie(View3DPerspective::getInstance());
	}

	// Le controller est un singleton
	Controller *controller = Controller::getInstance();

	// Démarre une boucle éternelle d'écoute des call back
	glutMainLoop();
	
	return 0;
}
