
#ifndef Fantassin_hpp
#define Fantassin_hpp
#include "Unite.hpp"

class Fantassin : public Unite
{

  public :
	
	Fantassin() : Unite(10, 10, 4, 1) {}
	
	~Fantassin() {}
	
	bool attaquer();
	
	void action3();
	
 	std::string getClasse() const
	{
		return "Fantassin";
	}
	
	Unite* ennemiAPortee();

};

#endif
