
#ifndef SuperSoldat_hpp
#define SuperSoldat_hpp
#include "Unite.hpp"
#include "Fantassin.hpp"

class SuperSoldat : public Unite
{
	 public :
	 
	
	SuperSoldat(Fantassin f){
		if(f.getPtsVie()==0){
			f.~Fantassin();
			SuperSoldat();
		}
		};
	
	SuperSoldat() : Unite(0, 10, 4, 1) {};
	
	~SuperSoldat() {}
	
	
	void attaquer();
	void action3();
	
	std::string getClasse() const
	{
		return "SuperSoldat";
	}

};

#endif
