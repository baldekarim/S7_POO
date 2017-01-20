
#ifndef Jeu_hpp
#define Jeu_hpp
#include "Singleton.hpp"
#include "Joueur.hpp"

class Jeu : public Singleton<Jeu>
{
	// Pour pouvoir acceder au constructeur et destructeur de Singleton uniquement dans cette classe
  friend class Singleton<Jeu>;
	
  private :
	
	int numeroTour;
	
	Joueur *joueurA, *joueurB, *joueurCourant;
	
	static const int nbMaxTour = 8; //static const int nbMaxTour = 100;
	
  public :
	
	Jeu();
	
	~Jeu() {
		delete joueurA;
		delete joueurB;
	}
	
	void actionsJeu();
	
	void tour();
	
	bool finJeu();
	
	void afficheEtatPlateau() const;
	
	void lancerJeu();
	
};

#endif
