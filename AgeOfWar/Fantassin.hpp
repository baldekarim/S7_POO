
#ifndef Fantassin_hpp
#define Fantassin_hpp
#include "Unite.hpp"
#include <iostream>

class Fantassin : public Unite
{
	
	public :
	Fantassin() : Unite(10, 10, 4, 1) {}
	~Fantassin() {}
	void affiche() const {
		std::cout<<"Fantassin"<<std::endl;
	}
};

#endif
