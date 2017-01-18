
#include "SuperSoldat.hpp"
using namespace std;

void SuperSoldat::attaquer()
{
	if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+1)){
	attack=true;
	cout << "Vous allez attaquer l'ennemi en position" << (this->numeroCase+1) <<endl ;
	cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
	}else
	attack=false;
	cout <<"Vous ne pouvez pas attaquer"<<endl;	
}

void SuperSoldat::action3()
{
	this->attaquer();
}
