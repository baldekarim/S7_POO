
#include "Joueur.hpp"

using namespace std;

bool Joueur::modifPlateau = false;

Joueur::Joueur(string n) : nom(n)
{
	solde = 0;
	saBase = new Base();
	cout<<"############# Bienvenu "<<nom<<" au jeu Age of War #############"<<endl<<endl;
}

void Joueur::resolutionActions()
{
	cout<<"\tRésolution des actions des unités du joueur : "<<nom<<endl<<endl;
    cout<<"\t\t Actions 1 : "<<endl<<endl;
	vector<Unite*>::reverse_iterator iter;
	for (iter = saBase->getUnites().rbegin(); iter != saBase->getUnites().rend(); iter++)
	{
		(*iter)->action1();
		//modifPlateau = true;
	}

	cout<<"\t\t Actions 2 : "<<endl<<endl;
	for(Unite *u : saBase->getUnites())
	{
		u->action2();
		//modifPlateau = true;
	}
	
	cout<<"\t\t Actions 3 : "<<endl<<endl;
	for(Unite *u : saBase->getUnites())
	{
		u->action3();
		//modifPlateau = true;
	}
}


void Joueur::recruterUnite()
{
	if(solde <= 10)
	{
		cout<<"\tLe solde de "<<nom<<" ne lui permet pas de recruter une unité"<<endl<<endl;
		return;
	}
	
	int indiceBase = saBase->getSens() == 'd' ? 0 : 11;
	
	
	if(Unite::getUnite(indiceBase) != NULL)
	{
		cout<<"\tLa base de "<<nom<<" est occupée par une autre unite il faut d'abord sortir cette unité de la base avant de recruter"<<endl<<endl;
		return;
	}
	
	strategieRecrutement(indiceBase);
	
	cout<<"\tLe solde actualisé de "<<nom<<" est : "<<solde<<endl<<endl;
	modifPlateau = true;
}

void Joueur::strategieRecrutement(int indiceBase)
{

	Unite *u;
	
	if(solde >= 10 && solde < 12)
	{
		u = new Fantassin();
		solde -= 10;
		cout<<"\t\tVous venez de recruter un fantassin"<<endl;
	}
	else if (solde >= 12 && solde < 20)
	{
		u = new Archer();
		solde -= 12;
		cout<<"\t\tVous venez de recruter un archer"<<endl;
	}
	else
	{
		u = new Catapulte();
		solde -= 20;
		cout<<"\t\tVous venez de recruter une catapulte"<<endl;
	}
	saBase->getUnites().push_back(u);
	Unite::setUnite(indiceBase, u);
	u->setNumeroCase(indiceBase, saBase->getSens());
	cout<<endl;
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
    //modifPlateau = true;
}
*/
