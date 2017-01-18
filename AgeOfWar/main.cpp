
#include <iostream>
#include "Jeu.hpp"
#include "Fantassin.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

	// pointeurs sur l'unique instance de la classe UniqueObject
	Fantassin u1;
	Fantassin u2;
	Jeu *jeu;
	// initialisation du pointeur
	jeu = Jeu::getInstance ();
	// lancement du jeu
	jeu->lancerJeu();
	// destruction de l'instance unique
	jeu->kill();

	return 0;
}
