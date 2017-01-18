
#include "Fantassin.hpp"
using namespace std;


void Fantassin::attaquer() {
	if(this->getEnnemi(cible) == true && cible->getUnite(this->numeroCase+1)){
	attack=true;
	cout << "Vous allez attaquer l'ennemi en position" << (this->numeroCase+1) <<endl ;
	cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
	cout<<"Points de vie unité touchée restants :"<< cible->getPtsVie()<<endl;
	}else
	attack=false;
	cible->setPtsVie(cible->getPtsVie()-this->getPtsAttaque());
	cout <<"Votre Fantassin ne peut pas attaquer"<<endl;
}

void Fantassin::action3(){
	if(this->action1()){
		cout <<"PAS D'ACTION POSSIBLE !"<<endl;
	}else
	this->attaquer();	
}
