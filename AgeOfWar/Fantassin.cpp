
#include "Fantassin.hpp"

using namespace std;

bool Fantassin::attaquer()
{
	Unite* cible = ennemiAPortee();
	if(cible == NULL)
		return false;
	else
	{
		cible->setPtsVie(cible->getPtsVie() - this->getPtsAttaque());
		cout<<"Votre unité a attaqué une unité ennemie :"<<endl;
		return true;
	}
}

Unite* Fantassin::ennemiAPortee()
{
	Unite* ennemi;
	if(this->getSensDeplacement() == 'd')
		ennemi = Unite::getUnite(this->numeroCase + 1);
	else
		ennemi = Unite::getUnite(this->numeroCase - 1);

	if(this->getSensDeplacement() != ennemi->getSensDeplacement())
		return ennemi;
	else
		return NULL;
}

void Fantassin::action3()
{
	if(this->action1Effectuee)
	{
		cout <<"Votre unité ne peut attaquer qu'une fois par tour car c'est un Fantassin !"<<endl;
	}
	else this->attaquer();
	
	// On réinitialise la variable action1Effectuee pour le prochain tour
	this->action1Effectuee = false;
}
