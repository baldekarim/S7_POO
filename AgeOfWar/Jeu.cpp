
#include "Jeu.hpp"

using namespace std;

Jeu::Jeu() : joueurA(0), joueurB(0), joueurCourant(0)
{
	joueurA = new Joueur("JoueurA", Base(0));
	joueurB = new Joueur("JoueurB", Base(11));
	numeroTour = 1;
	modifPlateau = false;
}

Case Jeu::getCase(int n) {
	return plateau[n];
}

Unite* Jeu::getUnite(Case c, Joueur j) {
	for (Unite *unite : j.getUnites())
	{
		if(unite->getCase().getNumero() == c.getNumero())
		{
			return unite;
		}
	}
	return NULL;
}

Unite Jeu::getUnite(Case c) {
	return *getUnite(c, *joueurCourant);
}

void Jeu::tour() {
	joueurA->augmenterSolde(8);
	joueurB->augmenterSolde(8);
	
	joueurCourant = joueurA;
	cout<<"Au tour de "<<joueurCourant->getNom()<<" de jouer"<<endl;
	joueurA->resolutionActions();
	joueurA->recruterUnite();
	if(modifPlateau) {
		modifPlateau = false;
		afficheEtatPlateau();
	}
	
	joueurCourant = joueurB;
    cout<<"Au tour de "<<joueurCourant->getNom()<<" de jouer"<<endl;
	joueurB->resolutionActions();
	joueurB->recruterUnite();
	if(modifPlateau) {
		modifPlateau = false;
		afficheEtatPlateau();
	}
	
	numeroTour++;
}

bool Jeu::finJeu() {
	if(numeroTour == nbMaxTour) {
		cout<<"Nombre maximum de tour atteint sans vainqueur => Fin du jeu"<<endl;
		return true;
	}
	if(joueurA->getBase().getPtsVie() <= 0) {
		cout<<"Le joueur "<<joueurB->getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"Vainqueur : "<<joueurB->getNom();
		return true;
	}
	if(joueurB->getBase().getPtsVie() <= 0) {
		cout<<"Le joueur "<<joueurA->getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"Vainqueur : "<<joueurA->getNom();
		return true;
	}
	return false;
}

void Jeu::lancerJeu() {
	while (!finJeu()) {
		tour();
	}
}

void Jeu::afficheEtatPlateau() const {
	cout<<"Nouvel etat du plateau après modifications : "<<endl;
	cout<<"Numero du tour : "<<numeroTour<<endl;
	cout<<"Unites presentes sur l'air de jeu : "<<endl;
	for (int i = 0; i < 12; i++) {
		/*if (plateau[i].getOccupe()) {
			cout<<"Case numero "<<i<<" : ";
			
			cout<<endl; // surcharger operateur de flux de la classe unité
		}*/
	}
	//...
}

void Jeu::combat(Unite &u1, Unite &u2) {
	
}

void Jeu::combat(Unite &u, Base &b) {
	
}
