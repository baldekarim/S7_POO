
#include "Fantassin.hpp"
using namespace std;


void Fantassin::attaquer() {
	if(this->getEnnemi(cible) == true && cible->getUnite(this->getPortee())){
	attack=true;
	cout << "Vous allez attaquer l'ennemi en position" << (this->getPortee()) <<endl ;
	cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
	}else
	attack=false;
	cout <<"Vous ne pouvez pas attaquer"<<endl;
}

void Fantassin::action3(){
	if(this->action1()){
		cout <<"PAS D'ACTION POSSIBLE !"<<endl;
	}else
	this->attaquer();	
}
