
#ifndef Jeu_hpp
#define Jeu_hpp
#include <iostream>
#include "Joueur.hpp"
#include "AireJeu.hpp"


class Jeu
{
	private :
	
	int numeroTour;
	Joueur joueurA, joueurB;
	AireJeu *sonAireJeu; // pointeur sur l'unique instance de la classe AireJeu
	static const int nbMaxTour = 100;
	
	public :
	
	Jeu() : joueurA(Joueur("JoueurA", Base(0))), joueurB(Joueur("JoueurA", Base(11)))
	{
		// initialisation du pointeur
		sonAireJeu = AireJeu::getInstance ();
		numeroTour = 1;
	}
	~Jeu() {}
	void tour();
	bool verifFinJeu();
	void combat(Unite, Unite);
	void combat(Unite, Base);
	void afficheEtatPlateau() const;
	
};

#endif
