
#ifndef Archer_hpp
#define Archer_hpp
#include "Unite.hpp"
#include <iostream>

class Archer : public Unite
{
	public :
	Archer() : Unite(12, 8, 3, 3) {}
	~Archer() {}
	void attaquer();
	
	
};

#endif
