
#ifndef Case_hpp
#define Case_hpp
#include <iostream>
#include "Unite.hpp"

class Case
{
	private :
	
	int numero;
	bool occupe;
	Unite *sonUnite;
	
	public :
	
	Case() {
		sonUnite = NULL;
	}
	Case(int n) : numero(n) {
		occupe = false;
		sonUnite = NULL;
	}
	~Case(){};
	void afficher(std::ostream &flux) const;
	int getNumero() const { return numero;}
	bool getOccupe() const { return occupe; }
	void setOccupe(bool o) {
		occupe = o;
	}
	Unite getUnite() const {
		return *sonUnite;
	}
	void setUnite(Unite u) {
		sonUnite = &u;
	}
	
};

#endif
