
#include "Joueur.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include "Unite.hpp"

using namespace std;

Joueur::Joueur(string n, const Base b) : nom(n), saBase(0) {
	solde = 0;
	saBase = new Base(b);
	std::cout<<"Bienvenu "<<nom<<" au jeu Age of War"<<std::endl;
}

void Joueur::resolutionActions()
{
	// Résolution actions 1
	vector<Unite*>::reverse_iterator iter;
	for (iter = sesUnites.rbegin(); iter != sesUnites.rend(); iter++) {
		(*iter)->action1();
	}

	// Résolution actions 2
	for(Unite *u : sesUnites) {
		u->action2();
	}
	
	// Résolutin actions 3
	for(Unite *u : sesUnites) {
		u->action3();
	}
}

void Joueur::recruterUnite()
{
	if(solde <= 10)
	{
		cout<<"Le solde de "<<nom<<" ne lui permet pas de recruter une unité"<<endl;
		return;
	}
	if(saBase->getOccupe())
	{
		cout<<"La base de "<<nom<<" est occupée par une autre unite il faut d'abord sortir cette unite de la base avant de recruter"<<endl;
		return;
	}
	if(sesUnites.empty())
	{
		Fantassin *f = new  Fantassin();
		solde -= 10;
		sesUnites.push_back(f);
		cout<<"Vous venez de recruter un fantassin"<<endl;
	}
	else if (solde >= 12 && solde < 20)
	{
		Archer *a = new Archer();
		solde -= 12;
		sesUnites.push_back(a);
		cout<<"Vous venez de recruter un archer"<<endl;
	}
	else
	{
		Catapulte *c = new Catapulte();
		solde -= 20;
		sesUnites.push_back(c);
		cout<<"Vous venez de recruter une catapulte"<<endl;
	}
	saBase->setOccupe(true);
	cout<<"Le solde actualisé de "<<nom<<" est : "<<solde<<endl;
}

void Joueur::supprimerUnite(Unite u)
{
	/*int postionElement = 0;
	 for (Unite &unite : sesUnites)
	 {
		if(unite == u)
		{
	 sesUnites.erase(sesUnites.begin() + postionElement);
		}
		postionElement++;
	 }*/
}

