
#ifndef Base_hpp
#define Base_hpp
#include "Unite.hpp"
#include <vector>

class Base
{
  private :
	
	int ptsVie;
	std::vector<Unite*> *sesUnites;
	char sensDeplacementUnites;
	
  public :
	
	Base() : ptsVie(100)
	{
		sesUnites = new std::vector<Unite*>;
	}
	
	~Base() {}
	
	int getPtsVie() const
	{
		return ptsVie;
	}

	void diminuerPtsVie(int p)
	{
		ptsVie -= p;
	}
	
	std::vector<Unite*> &getUnites() const
	{
		return *sesUnites;
	}
	
	char getSens() const
	{
		return sensDeplacementUnites;
	}
	
	void setSens(char c)
	{
		sensDeplacementUnites = c;
	}
		
};

#endif
