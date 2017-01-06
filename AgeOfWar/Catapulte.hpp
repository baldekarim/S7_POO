
#ifndef Catapulte_hpp
#define Catapulte_hpp
#include "Unite.hpp"
#include <iostream>

class Catapulte : public Unite
{
	public :
	Catapulte() : Unite(20, 12, 6, 4) {}
	~Catapulte() {}
	void attaquer();

};

#endif
