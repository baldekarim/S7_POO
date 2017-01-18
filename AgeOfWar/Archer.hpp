
#ifndef Archer_hpp
#define Archer_hpp
#include "Unite.hpp"

class Archer : public Unite
{
	

  public :
	
	Archer() : Unite(12, 8, 3, 3) {}
	
	~Archer() {}
	
	void attaquer();
	
	std::string getClasse() const
	{
		return "Archer";
	}
	
	void action3();
	
};

#endif
