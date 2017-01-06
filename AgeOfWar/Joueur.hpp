
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
	Base *saBase;
	std::vector<Unite*> sesUnites;
	
	public :
	
	Joueur(std::string n, const Base b);
	~Joueur() {
		delete saBase;
	}
	std::string getNom() const { return nom; }
	Base getBase() const { return *saBase; }
	void augmenterSolde(int s) {
		solde += s;
		std::cout<<"Le nouveau solde de "<<nom<<" est : "<<solde<<std::endl;
	}
	std::vector<Unite*> getUnites() const { return sesUnites; }
	void recruterUnite();
	void resolutionActions();
	void supprimerUnite(Unite);
	
};

#endif
