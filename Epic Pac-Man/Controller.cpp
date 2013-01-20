#include "Controller.h"

//#include "vld.h"
#include <ctime>

using namespace std;

// Permet de démarrer/stopper l'animation
int animation;

// Attibut qui retient l'instance de la classe (Pattern Singleton)
Controller *Controller::instance = 0;

/*
 * Fonction C qui appelle la méthode qui anime la bouche du Pac-Man
 */
// Chaque call back glut est délégué à une méthode de la classe View ou Controller
// Ceci est nécessaire car glut ne connait que les fonctions C.
void animateMouthPacmanCallBack(int val) {
	Controller::getInstance()->animateMouthPacman();
}

/*
 * Fonction C qui appelle la méthode qui déplace le Pac-Man automatiquement
 */
void animateDisplayCallBack(int val) {
	Controller::getInstance()->animateDisplay();
}

/*
 * Fonction C qui appelle la méthode qui gère le mode du pacman et du fantôme
 */
void animateModeCallBack(int val) {
	Controller::getInstance()->animateMode();
}

/*
 * Fonction C qui appelle la méthode qui gère la rotation du labyrinthe
 */
void animateRotationCallBack(int val) {
	Controller::getInstance()->animateRotation();
}

/*
 * Constructeur qui demande une instance du Model et de la View et qui initialise l'animation à 1
 * et la fin de partie à false (Pattern Singleton)
 */
Controller::Controller() {
	model = Model::getInstance();
	view = ViewContext::getInstance()->getStrategie();
	labyrinthe = model->getLabyrinthe();
	pacman = model->getPacman();
	fantome = model->getFantome();
	animation = 1;
	compteur = 0;

	// Lance le controleur de l'animation de la bouche du pacman
	glutTimerFunc(TEMPSBASE, animateMouthPacmanCallBack, animation);
	// Lance le controleur de l'animation qui gère les déplacements du pacman et du fantôme
	glutTimerFunc(VITESSE, animateDisplayCallBack, animation);

	if (typeid(*view) != typeid(View2D)) {
		// Si on n'est pas en 2D, lance le controleur de l'animation qui 
		// gère la rotation du labyrinthe
		glutTimerFunc(TEMPSBASE, animateRotationCallBack, 1);
	}

	srand(time(0));
}

/*
 * Destructeur
 */
Controller::~Controller() {
	// Vide car Singleton
}

/*
 * Getter de l'instance (Pattern Singleton)
 */
Controller *Controller::getInstance() {
	if (instance == 0)
		instance = new Controller();

	return instance;
}

/*
 * Méthode qui retire la pastille de la structure de données
 * en fonction de sa position x et y passée en paramètre
 */
void Controller::manger(int y, int x) {
	// Le pacman mange une pastille normale
	if (labyrinthe->getPastille(x, y) == 1) {
		labyrinthe->setPastille(x, y, -1);

		model->incScore(1);
		labyrinthe->decNbPastillesRestantes();
	// Le pacman mange une "super" pastille
	} else if (labyrinthe->getPastille(x, y) == 2) {
		labyrinthe->setPastille(x, y, -2);

		pacman->setSuper(true);
		fantome->setInvincible(false);
		compteur++;
		glutTimerFunc(TEMPSSUPER, animateModeCallBack, 1);
		model->incScore(10);
		labyrinthe->decNbPastillesRestantes();
	}

	// S'il ne reste plus aucune pastille on change de niveau
	if (labyrinthe->getNbPastillesRestantes() == 0) {
		// On sauvegarde l'état du labyrinthe (rotation ou pas)
		bool tmp = labyrinthe->isRotating();
		pacman->setMouthAnimated(model->chargerNiveau(model->getNiveau() + 1));
		pacman->setOrientationSuivante(LEFT);
		animation = pacman->isMouthAnimated();
		// On restaure l'ancien état du labyrinthe
		labyrinthe->setRotating(tmp);
	}
}

/*
 * Méthode qui initialise les pastilles dans le labyrinthe
 */
void Controller::initPastilles() {
	for (int x(0); x < labyrinthe->getHauteurLabyrinthe(); x++) {
		for (int y(0); y < labyrinthe->getLargeurLabyrinthe(); y++) {
			// Si un case du tableau de pastilles vaut -1 c'est qu'elle était occupée par une pastille normale
			if (labyrinthe->getPastille(x, y) == -1)
				labyrinthe->setPastille(x, y, 1);
			// Si un case du tableau de pastilles vaut -2 c'est qu'elle était occupée par une super pastille
			else if (labyrinthe->getPastille(x, y) == -2)
				labyrinthe->setPastille(x, y, 2);
		}
	}

	labyrinthe->setNbPastillesRestantes(labyrinthe->getNbPastillesTotal());
}

/*
 * Méthode qui change le mode de vue 3D en : 3D parallèle ou 3D perspective
 */
void Controller::changerMode() {
	int w = view->getWGlobal();
	int h = view->getHGlobal();

	if (typeid(*view) == typeid(View3D)) {
		ViewContext::getInstance()->setStrategie(View3DPerspective::getInstance());
		view = ViewContext::getInstance()->getStrategie();
		view->reshape(w, h);
	} else if (typeid(*view) == typeid(View3DPerspective)) {
		ViewContext::getInstance()->setStrategie(View3D::getInstance());
		view = ViewContext::getInstance()->getStrategie();
		view->reshape(w, h);
	}
}

/*
 * Méthode qui change la vue en 2D ou en 3D en fonction du mode désiré (3D parallère ou 3D perspective) passé en paramètre
 */
void Controller::changerVue(int mode) {
	int w = view->getWGlobal();
	int h = view->getHGlobal();

	if (typeid(*view) == typeid(View3D) || typeid(*view) == typeid(View3DPerspective)) {
		ViewContext::getInstance()->setStrategie(View2D::getInstance());
		view = ViewContext::getInstance()->getStrategie();
		view->reshape(w, h);
	}
	if (typeid(*view) == typeid(View2D)) {
		if (mode == 1) {
			ViewContext::getInstance()->setStrategie(View3D::getInstance());
		}
		else if (mode == 2) {
			ViewContext::getInstance()->setStrategie(View3DPerspective::getInstance());
		}
		view = ViewContext::getInstance()->getStrategie();
		view->reshape(w, h);
	}
}

/*
 * Méthode qui réinitialise la partie
 */
void Controller::reinitialiser() {
	initPastilles();
	pacman->setOrientationSuivante(LEFT);
	pacman->setPositionX(pacman->getPositionXInitiale());
	pacman->setPositionY(pacman->getPositionYInitiale());
	fantome->setPositionX(fantome->getPositionXInitiale());
	fantome->setPositionY(fantome->getPositionYInitiale());
	model->setScore(0);
	pacman->setSuper(false);
	pacman->setNbVies(3);
	pacman->notGameOver();
}

/*
 * Méthode qui quitte la partie
 */
void Controller::quitter() {
	labyrinthe->~Labyrinthe();
	std::exit(EXIT_SUCCESS);
}



/*
 * Méthode qui déplace le Pac-Man
 */
void Controller::deplacerPacman() {
	double positionX = pacman->getPositionX();
	double positionY = pacman->getPositionY();
	
	// On vérifie si la coordonnée est entière car c'est le seul cas où on peut changer l'orientation du Pac-Man
	if (Utils::isCoordEntiere(positionX, positionY)) {
		// On regarde l'orientation que l'utilisateur a choisis et on vérifie que le Pac-Man peut aller à cet endroit ou non
		switch (pacman->getOrientationSuivante()) {
			case LEFT :
				if (positionX <= 0 || !labyrinthe->isOuvert(positionX - PAS_NORMAL, -positionY)) {
					pacman->setMouthAnimated(false);
					return;
				}
				pacman->setOrientation(LEFT);
				break;
			case RIGHT :
				if (positionX >= (labyrinthe->getLargeurLabyrinthe() - 1) || !labyrinthe->isOuvert(positionX + PAS_NORMAL, -positionY)) {
					pacman->setMouthAnimated(false);
					return;
				}
				pacman->setOrientation(RIGHT);
				break;
			case UP :
				if (positionY >= 0 || !labyrinthe->isOuvert(positionX, -(positionY + PAS_NORMAL))) {
					pacman->setMouthAnimated(false);
					return;
				}
				pacman->setOrientation(UP);
				break;
			case DOWN :
				if (positionY <= -(labyrinthe->getHauteurLabyrinthe() - 1) || !labyrinthe->isOuvert(positionX, -(positionY - PAS_NORMAL))) {
					pacman->setMouthAnimated(false);
					return;
				}
				pacman->setOrientation(DOWN);
				break;
		}
	}

	// Déplacer le pacman en fonction de son orientation
	gererOrientationPacman(positionX, positionY);

	// Collision avec le fantôme
	gererCollisionsPacmanFantome();

	// Animation de la bouche
	pacman->setMouthAnimated(true);

	// Mange une pastille si dans une coordonnée entière
	if (Utils::isCoordEntiere(pacman->getPositionX(), pacman->getPositionY())) {
		manger(pacman->getPositionX(), -pacman->getPositionY());
	}
}

/*
 * Méthode qui déplace le Pac-Man en fonction de son orientation
 */
void Controller::gererOrientationPacman(double positionXPacman, double positionYPacman) {
	double nouvellePositionX = 0;
	double nouvellePositionY = 0;

	switch (pacman->getOrientation()) {
		case LEFT:
			nouvellePositionX = Utils::arrondiDeuxDecimale(positionXPacman - PAS);
			pacman->setPositionX(nouvellePositionX);
			break;
		case RIGHT:
			nouvellePositionX = Utils::arrondiDeuxDecimale(positionXPacman + PAS);
			pacman->setPositionX(nouvellePositionX);
			break;
		case UP:
			nouvellePositionY = Utils::arrondiDeuxDecimale(positionYPacman + PAS);
			pacman->setPositionY(nouvellePositionY);
			break;
		case DOWN:
			nouvellePositionY = Utils::arrondiDeuxDecimale(positionYPacman - PAS);
			pacman->setPositionY(nouvellePositionY);
			break;
	}
}

/*
 * Méthode qui déplace le Fantôme
 */
void Controller::deplacerFantome() {
	double positionX = fantome->getPositionX(), positionY = fantome->getPositionY(), nouvellePositionX = 0, nouvellePositionY = 0;
	
	// Gestion de l'orientation que le fantôme peut prendre
	gererOrientationFantome();
	
	// Déplace le Fantôme en fonction de son orientation
	switch (fantome->getOrientation()) {
		case LEFT:
			nouvellePositionX = Utils::arrondiDeuxDecimale(positionX - PAS);

			// Si le fantôme est bloqué par un mur on quitte la méthode
			if (positionX <= 0 || !labyrinthe->isOuvert(ceil(positionX - PAS_NORMAL), -positionY)) {
				return;
			}

			fantome->setPositionX(nouvellePositionX);
			break;
		case RIGHT:
			nouvellePositionX = Utils::arrondiDeuxDecimale(positionX + PAS);

			// Si le fantôme est bloqué par un mur on quitte la méthode
			// Ici l'arrondi est fait à l'intérieur de la méthode "isOuvert" (comme on caste à l'entier inférieur (int) suffit)
			if (positionX >= (labyrinthe->getLargeurLabyrinthe() - 1) || !labyrinthe->isOuvert(positionX + PAS_NORMAL, -positionY)) {
				return;
			}

			fantome->setPositionX(nouvellePositionX);
			break;
		case UP:
			nouvellePositionY = Utils::arrondiDeuxDecimale(positionY + PAS);

			// Si le fantôme est bloqué par un mur on quitte la méthode
			if (positionY >= 0 || !labyrinthe->isOuvert(positionX, ceil(-(positionY + PAS_NORMAL)))) {
				return;
			}

			fantome->setPositionY(nouvellePositionY);
			break;
		case DOWN:
			nouvellePositionY = Utils::arrondiDeuxDecimale(positionY - PAS);

			// Si le fantôme est bloqué par un mur on quitte la méthode
			// Ici l'arrondi est fait à l'intérieur de la méthode "isOuvert" (comme on caste à l'entier inférieur (int) suffit)
			if (positionY <= -(labyrinthe->getHauteurLabyrinthe() - 1) || !labyrinthe->isOuvert(positionX, -(positionY - PAS_NORMAL))) {
				return;
			}

			fantome->setPositionY(nouvellePositionY);
			break;
	}

	// Collision avec le Pac-Man
	gererCollisionsPacmanFantome();
}

/*
 * Gère les collisions entre le pacman et le fantôme
 */
void Controller::gererCollisionsPacmanFantome() {
	// Si le pacman touche un fantôme
	if (fantome->getPositionX() == pacman->getPositionX() && fantome->getPositionY() == pacman->getPositionY()) {
		if (pacman->isSuper()) {
			model->incScore(100);
			fantome->setPositionX(fantome->getPositionXInitiale());
			fantome->setPositionY(fantome->getPositionYInitiale());
		} else {
			pacman->decNbVies();
			pacman->setPositionX(pacman->getPositionXInitiale());
			pacman->setPositionY(pacman->getPositionYInitiale());
		}
	}
}

/*
 * Méthode qui anime la bouche du Pac-Man
 */
void Controller::animateMouthPacman() {
	// Util si on veut arrêter l'animation de la bouche du pac-man (par exemple à la fin d'un niveau lorsqu'on demande
	// à l'utilisateur s'il veut continuer ou rejouer le niveau
	if (pacman->isMouthAnimated() && pacman->getNbVies() > 0) {
		(pacman->getEtat() == MOUTH_OPENED) ? pacman->setEtat(MOUTH_CLOSED) : pacman->setEtat(MOUTH_OPENED);
		view->redraw(); // Rafraichissement de l'affichage
	}
	glutTimerFunc(BOUCHE, animateMouthPacmanCallBack, pacman->isMouthAnimated());
}

/*
 * Méthode qui gère le mode du pacman (super, normal) et le mode du fantôme (super, normal)
 */
void Controller::animateMode() {
	if (--compteur == 0) {
		pacman->setSuper(false);
		fantome->setInvincible(true);
	}
}

/*
 * Méthode qui appelle la méthode qui déplace le Pac-Man
 */
void Controller::animateDisplay() {
	if (animation && pacman->getNbVies() > 0) {
		deplacerPacman();
		deplacerFantome();
		view->redraw();
	}
	glutTimerFunc(VITESSE, animateDisplayCallBack, animation);
}

/*
 * Méthode qui gère la rotation du labyrinthe
 */
void Controller::animateRotation() {
	if (labyrinthe->isRotating()) {
		Camera::getInstance()->incAngleDeRotation();
	}
	glutTimerFunc(TEMPSBASE, animateRotationCallBack, 1);
}

/*
 * Méthode qui gère les contrôles de la souris en fonction du bouton, de son état et de sa positon x et y
 */
void Controller::mouse(int button, int state, int x_ecran, int y_ecran)  {
	Camera *camera = Camera::getInstance();
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);

		// Variables pour savoir dans quel intervalle se trouve la souris lorsque l'utilisateur clic
		double x_viewport = x_ecran - viewport[0];
		double y_viewport = view->getHGlobal() - viewport[1] - y_ecran;
		double x_dessin = view->getD1Controles() + x_viewport * (view->getDelta1Controles() / viewport[2]);
		double y_dessin = view->getD2Controles() + y_viewport * (view->getDelta2Controles() / viewport[3]);

		/* Contrôles du Jeu */
		// Bouton changer de vue en 2D
		if (x_dessin <= 4 && x_dessin >= -4 && y_dessin <= 16 && y_dessin >= 13) {
			if (typeid(*view) != typeid(View2D)) {
				changerVue(-1);
			}
		}
		// Bouton changer mode de vue en 3D parallèle
		if (x_dessin <= 4 && x_dessin >= -4 && y_dessin <= 12 && y_dessin >= 9) {
			if (typeid(*view) != typeid(View3D)) {
				changerMode();
			}
			if (typeid(*view) == typeid(View2D)) {
				changerVue(1);
			}
		}
		// Bouton changer mode de vue en 3D perspective
		if (x_dessin <= 4 && x_dessin >= -4 && y_dessin <= 8 && y_dessin >= 5) {
			if (typeid(*view) != typeid(View3DPerspective)) {
				changerMode();
			}
			if (typeid(*view) == typeid(View2D)) {
				changerVue(2);
			}
		}
		// Bouton rejouer
		if (x_dessin <= 4 && x_dessin >= -4 && y_dessin <= 4 && y_dessin >= 1) {
			reinitialiser();
		}
		// Bouton quitter
		if (x_dessin <= 4 && x_dessin >= -4 && y_dessin <= 0 && y_dessin >= -2) {
			quitter();
		}
		// Bouton +
		if (x_dessin <= 0 && x_dessin >= -4 && y_dessin <= -4 && y_dessin >= -6) {
			if (typeid(*view) == typeid(View3D)) {
				camera->zoomer3D();
			} else if (typeid(*view) == typeid(View3DPerspective)) {
				camera->zoomer3DPerspective();
			}
		}
		// Bouton -
		if (x_dessin <= 4 && x_dessin >= 0 && y_dessin <= -4 && y_dessin >= -6) {
			if (typeid(*view) == typeid(View3D)) {
				camera->dezoomer3D();
			} else if (typeid(*view) == typeid(View3DPerspective)) {
				camera->dezoomer3DPerspective();
			}
		}

		gererControlesPacman(x_dessin, y_dessin);
	}
}

/*
 * Méthode qui gère les déplacements du pacman en fonction de la direction
 * sélectionnée par l'utilisateur via un clic de souris (clic gauche)
 */
void Controller::gererControlesPacman(int x_dessin, int y_dessin) {
	/* Contrôles du Pac-Man */
	// Flèche haut
	if (x_dessin <= 1 && x_dessin >= -1 && y_dessin <= -7 && y_dessin >= -9) {
		pacman->setOrientationSuivante(UP);
	}
	// Flèche droite
	if (x_dessin <= 3 && x_dessin >= 1 && y_dessin <= -9 && y_dessin >= -11) {
		pacman->setOrientationSuivante(RIGHT);
	}
	// Flèche bas
	if (x_dessin <= 1 && x_dessin >= -1 && y_dessin <= -11 && y_dessin >= -14) {
		pacman->setOrientationSuivante(DOWN);
	}
	// Flèche gauche
	if (x_dessin <= -1 && x_dessin >= -3 && y_dessin <= -9 && y_dessin >= -11) {
		pacman->setOrientationSuivante(LEFT);
	}
}

/*
 * Méthode qui gère le click au centre de la scène pour faire tourner le labyrinthe
 */
void Controller::mousePicking(int button, int state, int x_ecran, int y_ecran)  {
	GLuint selectBuf[BUFSIZE];
	GLint hits;
	GLint viewport[4];

	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;

	viewport[0] = 0;
	viewport[1] = view->getYCoinInferieurGaucheViewportJeu();
	viewport[2] = view->getLargeurViewportJeu();
	viewport[3] = view->getHauteurViewportJeu();

	glSelectBuffer(BUFSIZE, selectBuf);
	// On rentre en mode de sélection
	glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(0);

	glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		// On crée une zone de picking de 5x5 pixel près du curseur de la souris
		gluPickMatrix((GLdouble) x_ecran, (GLdouble) (view->getHGlobal() - y_ecran), 20.0, 20.0, viewport);
		// glOrtho ou glPerspective
		view->projectionViewportJeu();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		double cameraX = (model->getLabyrinthe()->getLargeurLabyrinthe() - 1) / 2.0;
		double cameraY = (model->getLabyrinthe()->getHauteurLabyrinthe() - 1) / 2.0;
		gluLookAt(cameraX, -cameraY, 5, cameraX, -cameraY, 0, 0.0, 1.0, 0.0);
		glLoadName(1);
		// On dessine une forme pour le picking
		glPushMatrix();
			glTranslated(labyrinthe->getLargeurLabyrinthe()/2.0, -labyrinthe->getHauteurLabyrinthe()/2.0, 0.0);
				glRectd(-2.0, -2.0, 2.0, 2.0);
		glPopMatrix();
	glPopMatrix();

	// On applique les modifications
	glFlush();
	// On sort du mode de sélection pour entrer à nouveau en mode de rendu
	hits = glRenderMode(GL_RENDER);

	if (hits == 1) {
		// Faire la rotation
		labyrinthe->setRotating(labyrinthe->isRotating() ? false : true);
		glutPostRedisplay();
	}
}

/*
 * Méthode qui gère les flèches du clavier en fonction de la touche et sa position x et y
 */
void Controller::special(int key, int x, int y) {
	if (labyrinthe == 0) {
		return;
	}
	// Si le jeu n'est pas en pause et que la partie n'est pas terminée
	if (animation && pacman->getNbVies() > 0) {
		switch (key) {
			case GLUT_KEY_LEFT :
				pacman->setOrientationSuivante(LEFT);
				break;
			case GLUT_KEY_RIGHT :
				pacman->setOrientationSuivante(RIGHT);
				break;
			case GLUT_KEY_UP :
				pacman->setOrientationSuivante(UP);
				break;
			case GLUT_KEY_DOWN :
				pacman->setOrientationSuivante(DOWN);
				break;
		}

		// Rafraichissement de l'affichage
		view->redraw();
	}
}

/*
 * Méthode qui gère les contrôles du clavier en fonction de la touche et sa position x et y
 */
void Controller::keyboard(unsigned char key, int x, int y) {
	Camera *camera = Camera::getInstance();
	// Retient si le labyrinthe effectuais une rotation avant le changement de niveau
	bool tmp = false;
	// Retient si le labyrinthe effectuais une rotation avant la mise en pause du jeu
	static bool rotationAvantPause = false;

	switch (key) {
		case 'q':
		case 'Q':
			// Quitter
			quitter();
			break;
		case 'r':
		case 'R':
			// Réinitialiser la partie
			if (model->getLabyrinthe()->getNbPastillesRestantes() == 0 && model->getNiveau() >= NB_NIVEAUX) {
				model->chargerNiveau(1);
				pacman->setOrientationSuivante(LEFT);
				model->setScore(0);
				pacman->setSuper(false);
				pacman->setNbVies(3);
			} else {
				reinitialiser();
			}
			break;
		case '-':
			// Décrémenter les vies
			if (pacman->isGameOver()) {
				return;
			}
			pacman->decNbVies();
			break;
		case '+':
			// Incrémenter les vies
			if (pacman->isGameOver()) {
				return;
			}
			pacman->incNbVies();
			break;
		case SPACEBAR :
			// Pause
			if (animation) {
				animation = 0;
				if (pacman->isMouthAnimated()) {
					pacman->setMouthAnimated(false);
				}

				rotationAvantPause = labyrinthe->isRotating();
				// Lorsque le jeu est en pause on arrête la rotation
				labyrinthe->setRotating(false);
			} else {
				animation = 1;
				pacman->setMouthAnimated(true);
				labyrinthe->setRotating(rotationAvantPause);
			}
			break;
		case 'z' :
		case 'Z' :
			// Zoom en avant
			if (typeid(*view) == typeid(View3D)) {
				camera->zoomer3D();
			} else if (typeid(*view) == typeid(View3DPerspective)) {
				camera->zoomer3DPerspective();
			}
			break;
		case 's' :
		case 'S' :
			// Zoom en arrière
			if (typeid(*view) == typeid(View3D)) {
				camera->dezoomer3D();
			} else if (typeid(*view) == typeid(View3DPerspective)) {
				camera->dezoomer3DPerspective();
			}
			break;
		case 'l' :
		case 'L' :
			// Niveau suivant
			tmp = labyrinthe->isRotating();
			model->chargerNiveau(model->getNiveau()+1);
			pacman->setOrientationSuivante(LEFT);
			labyrinthe->setRotating(tmp);
			break;
		case 'k' :
		case 'K' :
			// Niveau précédent
			tmp = labyrinthe->isRotating();
			model->chargerNiveau(model->getNiveau()-1);
			pacman->setOrientationSuivante(LEFT);
			labyrinthe->setRotating(tmp);
			break;
	}
	
	// Rafraichissement de l'affichage
	view->redraw();
}

/*
 * Méthode qui indique si le Fantôme est bloqué par un mur du labyrinthe, elle renvoie
 * -1 s'il n'y a pas de collision, sinon elle renvoie la nouvelle direction (0=UP, 1=LEFT, 2=DOWN, 3=RIGHT)
 */
int Controller::collision() {
	int formeMur = labyrinthe->getMur(-fantome->getPositionY(), fantome->getPositionX());

	// Nous avons décidé de calculer les orientations possibles afin de ne pas renvoyer des orientations
	// erronées (ex: dire au fantôme de continuer tout droit alors qu'il est face à un mur).
	// Cette méthode est donc beaucoup plus longue mais est moins souvent appelée
	if (fantome->getOrientation() == UP) {
		if (formeMur == 1) {
			int orientationsPossibles[3] = {LEFT, DOWN, RIGHT};
			return orientationsPossibles[rand() % 3];
		}
		if (formeMur == 5) {
			int orientationsPossibles[2] = {LEFT, DOWN};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 6) {
			int orientationsPossibles[2] = {DOWN, RIGHT};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 10) {
			int orientationsPossibles[2] = {LEFT, RIGHT};
			return orientationsPossibles[rand() % 2];
		}

		return -1;
	}

	if (fantome->getOrientation() == LEFT) {
		if (formeMur == 3) {
			int orientationsPossibles[3] = {UP, RIGHT, DOWN};
			return orientationsPossibles[rand() % 3];
		}
		if (formeMur == 6) {
			int orientationsPossibles[2] = {RIGHT, DOWN};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 8) {
			int orientationsPossibles[2] = {UP, RIGHT};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 9) {
			int orientationsPossibles[2] = {UP, DOWN};
			return orientationsPossibles[rand() % 2];
		}

		return -1;
	}

	if (fantome->getOrientation() == DOWN) {
		if (formeMur == 2) {
			int orientationsPossibles[3] = {LEFT, UP, RIGHT};
			return orientationsPossibles[rand() % 3];
		}
		if (formeMur == 7) {
			int orientationsPossibles[2] = {UP, LEFT};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 8) {
			int orientationsPossibles[2] = {UP, RIGHT};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 10) {
			int orientationsPossibles[2] = {LEFT, RIGHT};
			return orientationsPossibles[rand() % 2];
		}

		return -1;
	}

	if (fantome->getOrientation() == RIGHT) {
		if (formeMur == 4) {
			int orientationsPossibles[3] = {UP, LEFT, DOWN};
			return orientationsPossibles[rand() % 3];
		}
		if (formeMur == 5) {
			int orientationsPossibles[2] = {LEFT, DOWN};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 7) {
			int orientationsPossibles[2] = {UP, LEFT};
			return orientationsPossibles[rand() % 2];
		}
		if (formeMur == 9) {
			int orientationsPossibles[2] = {UP, DOWN};
			return orientationsPossibles[rand() % 2];
		}

		return -1;
	}

	return -1;
}

/*
 * Méthode qui gère l'orientation du fantôme
 */
void Controller::gererOrientationFantome() {
	if (Utils::isEntier(fantome->getPositionX()) && Utils::isEntier(fantome->getPositionY())) {
		int formeMur = labyrinthe->getMur(-fantome->getPositionY(), fantome->getPositionX());

		/* Si on a une collision (le fantôme rencontre un mur et ne peut plus avancer),
		 * on change l'orientation du fantôme jusqu'à ce qu'il n'y ait plus de collision
		 */
		while (1) {
			int orientation = collision();

			if (orientation != -1) {
				fantome->setOrientation(orientation);
			// S'il n'y a pas de collision on gère les cas ou le fantôme peut
			// emprunter 3 directions ou plus pour qu'il puisse parcourir tout le labyrinthe
			} else {
				// S'il n'y a pas de collisions on regarde si le fantôme à le choix entre plusieurs directions
				if (formeMur == 0) {
					fantome->setOrientation(rand() % 4);
				} else if (formeMur == 1) {
					int orientationsPossibles[3] = {LEFT, DOWN, RIGHT};
					fantome->setOrientation(orientationsPossibles[rand() % 3]);
				} else if (formeMur == 2) {
					int orientationsPossibles[3] = {LEFT, UP, RIGHT};
					fantome->setOrientation(orientationsPossibles[rand() % 3]);
				} else if (formeMur == 3) {
					int orientationsPossibles[3] = {UP, RIGHT, DOWN};
					fantome->setOrientation(orientationsPossibles[rand() % 3]);
				} else if (formeMur == 4) {
					int orientationsPossibles[3] = {UP, LEFT, DOWN};
					fantome->setOrientation(orientationsPossibles[rand() % 3]);
				} else if (formeMur == 10 && (fantome->getPositionX() <= 0 || fantome->getPositionX() >= labyrinthe->getLargeurLabyrinthe()-1)) {
					if (fantome->getOrientation() == LEFT) {
						fantome->setOrientation(RIGHT);
					} else if (fantome->getOrientation() == RIGHT) {
						fantome->setOrientation(LEFT);
					}
				}

				break;
			}
		}
	}
}
