
#include "Catapulte.hpp"

using namespace std;

void Catapulte::attaquer()
{
	if(cible->getUnite(this->numeroCase+1))
	cout<<"C'est la position du second ennemi qui sera attaqué"<<endl;
	else{
		if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+2) && cible->getUnite(this->numeroCase+3)){ //Cas où c+1
		attack=true;
		position = this->numeroCase+1;
		cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
		}else if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+3) && cible->getUnite(this->numeroCase+4)){ //Cas où c+1
		attack=true;
		position = this->numeroCase+1;
		cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
		}
	}	
}

void Catapulte::action2()
{
	cout<<"Vous ne pouvez pas effectuer de deuxième action car votre unité est une :"<< this->getClasse() <<endl;
}

void Catapulte::action3(){
	if(this->action1()){
		cout <<"PAS D'ACTION POSSIBLE !"<<endl;
	}else
	this->attaquer();	
}
