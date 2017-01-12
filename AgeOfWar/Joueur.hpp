
#ifndef Joueur_hpp
#define Joueur_hpp
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"

class Joueur
{
	
  private :
	
	std::string nom;
	int solde;
	Base *saBase;
	
  public :
	
	Joueur(std::string n);
	
	~Joueur()
	{
		delete saBase;
	}
	
	std::string getNom() const
	{
		return nom;
	}
	
	Base *getBase() const
	{
		return saBase;
	}
	
	void augmenterSolde(int s)
	{
		solde += s;
		std::cout<<"Le nouveau solde de "<<nom<<" est : "<<solde<<std::endl;
	}
	
	void recruterUnite();
	
	void resolutionActions();
	
	//void supprimerUnite(Unite);
	
};

#endif
