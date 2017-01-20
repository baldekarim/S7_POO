
#ifndef Catapulte_hpp
#define Catapulte_hpp
#include "Unite.hpp"

class Catapulte : public Unite
{
  protected:
  static int position;
  public :
	
	Catapulte() : Unite(20, 12, 6, 4) {}
	
	~Catapulte() {}
	
	bool attaquer();
	
	std::string getClasse()const
	{
		return "Catapulte";
	}
	
	Unite* ennemiAPortee();
	
	void action2();
	
	void action3();

};

#endif
