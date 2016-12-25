
#include "Jeu.hpp"

using namespace std;

void Jeu::tour() {
	joueurA.augmenterSolde(8);
	joueurB.augmenterSolde(8);
	joueurA.resolutionActions();
	joueurA.recruterUnite();
	joueurB.resolutionActions();
	joueurB.recruterUnite();
	numeroTour++;
}

bool Jeu::verifFinJeu() {
	if(numeroTour == nbMaxTour) {
		cout<<"Nombre maximum de tour atteint sans vainqueur => Fin du jeu"<<endl;
		return true;
	}
	if(joueurA.getBase().getPtsVie() <= 0) {
		cout<<"Le joueur "<<joueurB.getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"Vainqueur : "<<joueurB.getNom();
		return true;
	}
	if(joueurB.getBase().getPtsVie() <= 0) {
		cout<<"Le joueur "<<joueurA.getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"Vainqueur : "<<joueurA.getNom();
		return true;
	}
	return false;
}

void Jeu::afficheEtatPlateau() const {
	cout<<"Nouvel etat du plateau apres modifications : "<<endl;
	cout<<"Numero du tour : "<<numeroTour<<endl;
	cout<<"Unites presentes sur l'air de jeu : "<<endl;
	//...
}

void Jeu::combat(Unite, Unite) {
	
}

void Jeu::combat(Unite, Base) {
	
}
