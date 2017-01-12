
#include "Joueur.hpp"

using namespace std;

Joueur::Joueur(string n) : nom(n)
{
	solde = 0;
	saBase = new Base();
	cout<<"Bienvenu "<<nom<<" au jeu Age of War"<<endl;
}

void Joueur::resolutionActions()
{
	cout<<"Résolution actions  "<<nom<<endl;
	// Résolution actions 1
	vector<Unite*>::reverse_iterator iter;
	for (iter = saBase->getUnites().rbegin(); iter != saBase->getUnites().rend(); iter++)
	{
		cout<<"Action 1 Unité  "<<nom<<endl; //
		(*iter)->action1();
	}

	// Résolution actions 2
	for(Unite *u : saBase->getUnites())
	{
		cout<<"Action 2 Unité  "<<nom<<endl; //
		u->action2();
	}
	
	// Résolutin actions 3
	for(Unite *u : saBase->getUnites())
	{
		cout<<"Action 3 Unité  "<<nom<<endl; //
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
	
	int indiceBase;
	if(saBase->getSens() == 'd')
	{
		indiceBase = 0;
	}
    else
	{
		indiceBase = 11;
	}
	
	if(Unite::getUnite(indiceBase) != NULL)
	{
		cout<<"La base de "<<nom<<" est occupée par une autre unite il faut d'abord sortir cette unité de la base avant de recruter"<<endl;
		return;
	}
	
	if(solde >= 10 && solde < 12)
	{
		Fantassin *f = new  Fantassin();
		solde -= 10;
		saBase->getUnites().push_back(f);
		Unite::setUnite(indiceBase, f);
		f->setNumeroCase(indiceBase, saBase->getSens());
		cout<<"Vous venez de recruter un fantassin"<<endl;
	}
	else if (solde >= 12 && solde < 20)
	{
		Archer *a = new Archer();
		solde -= 12;
		saBase->getUnites().push_back(a);
		Unite::setUnite(indiceBase, a);
		a->setNumeroCase(indiceBase, saBase->getSens());
		cout<<"Vous venez de recruter un archer"<<endl;
	}
	else
	{
		Catapulte *c = new Catapulte();
		solde -= 20;
		saBase->getUnites().push_back(c);
		Unite::setUnite(indiceBase, c);
		c->setNumeroCase(indiceBase, saBase->getSens());
		cout<<"Vous venez de recruter une catapulte"<<endl;
	}
	
	cout<<"Le solde actualisé de "<<nom<<" est : "<<solde<<endl;
}

/*void Joueur::supprimerUnite(Unite u)
{
	int postionElement = 0;
	 for (Unite &unite : sesUnites)
	 {
		if(unite == u)
		{
	 sesUnites.erase(sesUnites.begin() + postionElement);
		}
		postionElement++;
	 }
}
*/
