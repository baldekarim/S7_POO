
#include "Jeu.hpp"

using namespace std;

bool Jeu::modifPlateau = false;

Jeu::Jeu() : joueurA(0), joueurB(0), joueurCourant(0)
{
	joueurA = new Joueur("JoueurA");
	(joueurA->getBase())->setSens('d');
	joueurB = new Joueur("JoueurB");
	(joueurB->getBase())->setSens('g');
	numeroTour = 1;
}

void Jeu::tour()
{
	cout<<" Tour "<<numeroTour<<" :"<<endl;
	joueurA->augmenterSolde(8);
	joueurB->augmenterSolde(8);
	
	joueurCourant = joueurA;
	cout<<"Au joueur : "<<joueurCourant->getNom()<<" de jouer"<<endl;
	joueurA->resolutionActions();
	joueurA->recruterUnite();
	if(modifPlateau)
	{
		modifPlateau = false;
		afficheEtatPlateau();
	}
	
	joueurCourant = joueurB;
    cout<<"Au joueur : "<<joueurCourant->getNom()<<" de jouer"<<endl;
	joueurB->resolutionActions();
	joueurB->recruterUnite();
	if(modifPlateau)
	{
		modifPlateau = false;
		afficheEtatPlateau();
	}
	
	numeroTour++;
}

bool Jeu::finJeu()
{
	if(numeroTour == nbMaxTour)
	{
		cout<<"Nombre maximum de tour atteint sans vainqueur => Fin du jeu"<<endl;
		return true;
	}
	if(joueurA->getBase()->getPtsVie() <= 0)
	{
		cout<<"Le joueur "<<joueurB->getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"Vainqueur : "<<joueurB->getNom();
		return true;
	}
	if(joueurB->getBase()->getPtsVie() <= 0)
	{
		cout<<"Le joueur "<<joueurA->getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"Vainqueur : "<<joueurA->getNom();
		return true;
	}
	
	return false;
}

void Jeu::lancerJeu()
{
	while (!finJeu())
	{
		tour();
		
		cout<<"Tapez la 'Entrer' du clavier pour passer au tour suivant ou la touche 'q' du pour quitter le jeu : "<<endl;
		char s = getchar();
		while(s != 'q' && s != '\n') {
			cout<<"Erreur de saisie vous devez tapez la touche 'q' ou 'Entrer'"<<endl;
			s = getchar();
		}
		if(s == 'q')
		{
			cout<<"Vous allez quittez le jeu "<<endl;
			return;
		}
		else if(s == '\n')
		{
			continue;
		}
	}
}

void Jeu::afficheEtatPlateau() const
{
	cout<<"Nouvel etat du plateau après modifications : "<<endl;
	cout<<"Numero du tour : "<<numeroTour<<endl;
	cout<<"Unites presentes sur l'air de jeu : "<<endl;
	/*for (int i = 0; i < 12; i++) {
		if (plateau[i].getOccupe()) {
			cout<<"Case numero "<<i<<" : ";
			
			cout<<endl; // surcharger operateur de flux de la classe unité
		}
	}*/
}
