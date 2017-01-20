
#include "Jeu.hpp"

using namespace std;

Jeu::Jeu() : joueurA(0), joueurB(0), joueurCourant(0)
{
	joueurA = new Joueur("JoueurA");
	(joueurA->getBase())->setSens('d');
	joueurB = new Joueur("JoueurB");
	(joueurB->getBase())->setSens('g');
	numeroTour = 1;
}

void Jeu::actionsJeu()
{
	cout<<"---> Au joueur : "<<joueurCourant->getNom()<<" de jouer"<<endl<<endl;
	joueurCourant->resolutionActions();
	joueurCourant->recruterUnite();
}

void Jeu::tour()
{
	cout<<"\t////////// Tour "<<numeroTour<<" ////////// "<<endl<<endl;
	
	joueurA->augmenterSolde(8);
	joueurB->augmenterSolde(8);
	
	joueurCourant = joueurA;
	
	actionsJeu();
	
	joueurCourant = joueurB;
	
	actionsJeu();
	
	numeroTour++;
	
	if(Joueur::modifPlateau)
	{
		Joueur::modifPlateau = false;
		afficheEtatPlateau();
	}
}

bool Jeu::finJeu()
{
	if(numeroTour == nbMaxTour)
	{
		cout<<"\n\tNombre maximum de tour atteint sans vainqueur => Fin du jeu\n"<<endl;
		return true;
	}
	if(joueurA->getBase()->getPtsVie() <= 0)
	{
		cout<<"\n\tLe joueur "<<joueurB->getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"\n\t\t\tVainqueur : "<<joueurB->getNom()<<endl<<endl;
		return true;
	}
	if(joueurB->getBase()->getPtsVie() <= 0)
	{
		cout<<"\n\tLe joueur "<<joueurA->getNom()<<" a reussi a detruire la base adverse"<<endl;
		cout<<"\n\t\t\tVainqueur : "<<joueurA->getNom()<<endl<<endl;
		return true;
	}
	
	return false;
}

void Jeu::lancerJeu()
{
	do
	{
		tour();
		
		cout<<"Tapez la touche 'Entrer' du clavier pour passer au tour suivant ou la touche 'q' pour quitter le jeu : "<<endl;
		char s = getchar();
		while(s != 'q' && s != '\n') {
			cout<<"Erreur de saisie vous devez tapez la touche 'q' ou 'Entrer'"<<endl;
			s = getchar();
		}
		if(s == 'q')
		{
			cout<<"\nVous allez quittez le jeu "<<endl;
			return;
		}
		else if(s == '\n')
		{
			continue;
		}
	}
	while (!finJeu());
}

void Jeu::afficheEtatPlateau() const
{
	cout<<"Unités encore presentes sur l'air de jeu : \n"<<endl;
	for (int i = 0; i < 12; i++)
	{
		Unite *u = Unite::getUnite(i);
		if(u != NULL)
		{
			cout<<*u<<endl<<endl;
		}

	}
}
