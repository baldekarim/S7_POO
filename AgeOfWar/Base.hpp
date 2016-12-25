
#ifndef Base_hpp
#define Base_hpp
#include <iostream>
#include "Case.hpp"

class Base : public Case
{
	private :
	
	int ptsVie;
	
	public :
	
	Base(int n) : Case(n), ptsVie(100) {}
	~Base() {}
	int getPtsVie() const { return ptsVie; }
	void diminuerPtsVie(int p) {
		ptsVie -= p;
	}
	
};

#endif
