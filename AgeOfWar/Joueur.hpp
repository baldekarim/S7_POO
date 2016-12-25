
#ifndef Joueur_hpp
#define Joueur_hpp
#include <iostream>
#include <string>
#include "Unite.hpp"
#include <vector>
#include "Base.hpp"
#include <iostream>

class Joueur
{
	private :
	
	std::string nom;
	int solde;
	Base saBase;
	std::vector<Unite> sesUnites;
	
	public :
	
	Joueur(std::string n, const Base b) : nom(n), saBase(b) {
		solde = 0;
		std::cout<<"Bienvenu "<<nom<<" au jeu Age of War"<<std::endl;
	}
	~Joueur() {}
	std::string getNom() const { return nom; }
	Base getBase() const { return saBase; }
	void augmenterSolde(int s) {
		solde += s;
		std::cout<<"Le nouveau solde de "<<nom<<" est : "<<solde<<std::endl;
	}
	void recruterUnite();
	void resolutionActions();
	void supprimerUnite(Unite);
	
};

#endif
