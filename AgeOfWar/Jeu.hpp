
#ifndef Jeu_hpp
#define Jeu_hpp
#include <iostream>
#include "Singleton.hpp"
#include "Joueur.hpp"
//#include "AireJeu.hpp"


class Jeu : public Singleton<Jeu>
{
	// Pour pouvoir acceder au constructeur et destructeur de Singleton uniquement dans cette classe
	friend class Singleton<Jeu>;
	
	private :
	
	Case plateau[12];
	int numeroTour;
	Joueur *joueurA, *joueurB;
	Joueur *joueurCourant;
	static const int nbMaxTour = 5; //static const int nbMaxTour = 100;
	
	public :
	
	static bool modifPlateau;
	Jeu();
	~Jeu() {
		delete joueurA;
		delete joueurB;
	}
	void tour();
	bool finJeu();
	void combat(Unite&, Unite&);
	void combat(Unite&, Base&);
	void afficheEtatPlateau() const;
	/*Case* getPlateau() const {
		return plateau;
	};*/
	Case getCase(int n);
	Unite getUnite(Case c);
	Unite *getUnite(Case c, Joueur j);
	void lancerJeu();
	
};

#endif
