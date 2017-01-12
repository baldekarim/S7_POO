
#ifndef Catapulte_hpp
#define Catapulte_hpp
#include "Unite.hpp"

class Catapulte : public Unite
{
  public :
	
	Catapulte() : Unite(20, 12, 6, 4) {}
	
	~Catapulte() {}
	
	void attaquer();
	
	std::string getClasse()const
	{
		return "Catapulte";
	}
	
	void action2();

};

#endif
