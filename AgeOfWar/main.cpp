
#include <iostream>
#include "AireJeu.hpp"
#include "Joueur.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	
	// pointeurs sur l'unique instance de la classe UniqueObject
	// AireJeu *obj1, *obj2;
	
	// initialisation des pointeurs
	// obj1 = AireJeu::getInstance ();
	// obj2 = AireJeu::getInstance ();
	
	// affectation de la valeur 15 à l'objet pointé par obj1
	//obj1->setCase(1, Case(1, true));
	
	// affichage de _value
	// cout << "obj1 = " << obj1->getCase(1).getNumero() <<endl;
	// cout << obj1->getCase(1).operator<<(cout)<<endl;
	
	// destruction de l'instance unique
	//obj1->kill ();
	Joueur joueurA = Joueur("JoueurA", Base(0));
	joueurA.recruterUnite();
	joueurA.augmenterSolde(25);
	joueurA.recruterUnite();
	joueurA.recruterUnite();
	
	return 0;
}
