
#ifndef AireJeu_hpp
#define AireJeu_hpp
#include <iostream>
#include "Case.hpp"
#include "Singleton.hpp"

class AireJeu : public Singleton<AireJeu>
{
	// Pour pouvoir acceder au constructeur et destructeur de Singleton uniquement dans cette classe
	friend class Singleton<AireJeu>;
	
	private :
	// variable membre : l'aire de jeu comporte 12 cases
	Case plateau[12];
	// Constructeur/destructeur
	AireJeu ()
	{
		for (int i = 0; i < 12; i++) {
			plateau[i] = Case(i);
		}
	}
	~AireJeu () { }
	
	public :
	void setCase(int i, Case c) {
		std::cout<<"modif en cours "<<std::endl;
		plateau[i] = c;
	}
	Case getCase(int i) {
		return plateau[i];
	}
	
};

#endif
