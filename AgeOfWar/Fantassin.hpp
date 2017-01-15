
#ifndef Fantassin_hpp
#define Fantassin_hpp
#include "Unite.hpp"
#define Unite_hpp
#include <iostream>

class Fantassin : public Unite
{

  public :
	
	Fantassin() : Unite(10, 10, 4, 1) {}
	
	~Fantassin() {}
	
	void attaquer();
	void action3();
	
 	std::string getClasse() const
	{
		return "Fantassin";
	}

};

#endif
