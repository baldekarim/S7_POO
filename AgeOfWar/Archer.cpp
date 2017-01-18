
#include "Archer.hpp"

using namespace std;

void Archer::attaquer()
{
	if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+2)){ //Cas où c+1
	attack=true;
	position = this->numeroCase+1;
	cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
	cout<<"Points de vie unité touchée restants :"<< cible->getPtsVie()<<endl;
	}else if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+2)){ //Cas où c+2
	attack=true;
	position = this->numeroCase+2;
	cible->setPtsVie(cible->getPtsVie()- this->getPtsAttaque());
	cout<<"Points de vie unité touchée restants :"<< cible->getPtsVie()<<endl;
	}else if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+3)){ //Cas où c+3
	attack=true;
	position = this->numeroCase+3;
	cible->setPtsVie(cible->getPtsVie()- this->getPtsAttaque());
	cout<<"Points de vie unité touchée restants :"<< cible->getPtsVie()<<endl;
	}else{
	attack=false;
	}
	
	if(attack==true)
	cout << "Vous allez attaquer l'ennemi en position" << (this->position) <<endl ;
	if(attack==false)
	cout << "Vous ne pouvez pas attaquer"<<endl;
}

void Archer::action3()
{
	cout<<"Vous ne pouvez pas effectuer de troisieme action car votre unité est un Archer"<<endl;
}
