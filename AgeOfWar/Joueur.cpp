
#include "Joueur.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include "Unite.hpp"

using namespace std;

void Joueur::resolutionActions()
{
	
}

void Joueur::recruterUnite()
{
	if(solde <= 10)
	{
		cout<<"Le solde de "<<nom<<" ne lui permet pas de recruter une unite"<<endl;
		return;
	}
	if(saBase.getOccupe())
	{
		cout<<"La base de "<<nom<<" est occupee par une autre unite il faut d'abord sortir cette unite de la base avant de recruter"<<endl;
		return;
	}
	if(sesUnites.empty())
	{
		Fantassin f = Fantassin();
		solde -= 10;
		sesUnites.push_back(f);
		cout<<"Vous venez de recruter un fantassin"<<endl;
	}
	else if (solde >= 12 && solde < 20)
	{
		Archer a = Archer();
		solde -= 12;
		sesUnites.push_back(a);
		cout<<"Vous venez de recruter un archer"<<endl;
	}
	else
	{
		Catapulte c = Catapulte();
		solde -= 20;
		sesUnites.push_back(c);
		cout<<"Vous venez de recruter une catapulte"<<endl;
	}
	saBase.setOccupe(true);
	cout<<"Le solde actualise de "<<nom<<" est : "<<solde<<endl;
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

