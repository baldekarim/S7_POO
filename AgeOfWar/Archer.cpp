
#include "Archer.hpp"

using namespace std;

bool Archer::attaquer()
{
	
	Unite* cible = ennemiAPortee();
	
	if(cible == NULL)
		return false;
	else
	{
		cible->setPtsVie(cible->getPtsVie() - this->getPtsAttaque());
		cout<<"Votre archer a touché une cible adverse à la case "<<cible->getNumeroCase()<<endl;
		return true;
	}
}

/* On cherche la première unité ennemie la plus proche soit on la trouve entre les 
   cases c+1 et c+3 dans ce cas on la renvoie soit on ne trouve pas dans ce cas on 
   renvoie NULL
 */
Unite* Archer::ennemiAPortee()
{
	Unite* u = NULL;
	int i = 1;
	do
	{
		if(this->getSensDeplacement() == 'd')
			u = Unite::getUnite(this->getNumeroCase() + i);
		else
			u = Unite::getUnite(this->getNumeroCase() - i);
		i++;
		if(u != NULL && this->getSensDeplacement() != u->getSensDeplacement())
			break;
	} while (i <= 3);
	
	return u;
}


void Archer::action3()
{
	cout<<"Votre unité ne peut pas effectuer de troisième action car c'est un Archer"<<endl;
}

