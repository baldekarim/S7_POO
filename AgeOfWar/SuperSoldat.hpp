
#ifndef SuperSoldat_hpp
#define SuperSoldat_hpp
#include "Unite.hpp"

class SuperSoldat : public Unite
{
	
	void attaquer();
	
	std::string getClasse() const
	{
		return "SuperSoldat";
	}

};

#endif
