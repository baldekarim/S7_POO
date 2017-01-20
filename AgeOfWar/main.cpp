
#include <iostream>
#include "Jeu.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

	// pointeurs sur l'unique instance de la classe UniqueObject
	Jeu *jeu;
	// initialisation du pointeur
	jeu = Jeu::getInstance ();
	// lancement du jeu
	jeu->lancerJeu();
	// destruction de l'instance unique
	jeu->kill();
	
	return 0;
}
