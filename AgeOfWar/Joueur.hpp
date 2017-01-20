
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
	
	Joueur(std::string);
	
	~Joueur()
	{
		delete saBase;
	}
	
	static bool modifPlateau;
	
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
		std::cout<<"Le nouveau solde de "<<nom<<" est : "<<solde<<"\n"<<std::endl;
	}
	
	void recruterUnite();
	
	void resolutionActions();
	
	void strategieRecrutement(int);
	
	//void supprimerUnite(Unite);
	
};

#endif
