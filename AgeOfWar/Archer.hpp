
#ifndef Archer_hpp
#define Archer_hpp
#include "Unite.hpp"

class Archer : public Unite
{
	
  private :
  static int position;

  public :
	
	Archer() : Unite(12, 8, 3, 3) {}
	
	~Archer() {}
	
	Unite* ennemiAPortee();
	
	bool attaquer();
	
	std::string getClasse() const
	{
		return "Archer";
	}
	
	void action3();
	
};

#endif
