
#ifndef Unite_hpp
#define Unite_hpp
#include <iostream>
#include "Case.hpp"

class Unite
{
	private :
	
	int prix;
	int ptsVie;
	int ptsAttaque;
	int portee;
	int numeroCase;
	Case *saCase;
	
    public:
	
	Unite() {}
	Unite(int p, int v, int a, int por) : prix(p), ptsVie(v), ptsAttaque(a), portee(por) {}
	virtual ~Unite() {}
	//bool estEgal(Unite const& u)const;
	void avancer();
	Case getCase() { return *saCase; }
	virtual void attaquer() = 0;
	void action1();
	void action2();
	void action3();
	
};

/*bool operator==(Unite const& u1, Unite const& u2) {
	return u1.estEgal(u2);
}*/

#endif
// surcharger operateur== (suggestion ci-dessus), définir méthode getCase qui renvoie la case de l'unité
