
#include "Unite.hpp"

using namespace std;

bool Unite::init = false;

Unite::Unite(int p, int v, int a, int por) : prix(p), ptsVie(v), ptsAttaque(a), portee(por)
{
	if(!init)
	{
		init = true;
		creerMap();
	}
}

 // GESTION DES ACTIONS POSSIBLES

bool Unite::action1()
{
	attaquer();
	return true; //Pour l'instant mais il faudra renvoyer vrai si l'unité à pu attaquer
}

void Unite::action2()
{
	avancer();
}

void Unite::action3()
{
	
}

void Unite::avancer()
{
	int pasAvancement;
	if(sensDeplacement == 'd') pasAvancement = 1;
	else pasAvancement = -1;
	if(getUnite(numeroCase + pasAvancement) != NULL)
	{
		cout << "La case suivante est occupée : Votre unité ne peut pas avancer" << endl;
	}
	else
	{
		setUnite(numeroCase, NULL);
		numeroCase += pasAvancement;
		setUnite(numeroCase, this);
		cout << "Votre unité vient d'avancer d'une case \t Nouvelle postion : Case "<<numeroCase<< endl;
	}
}

Unite::mapT Unite::creerMap()
{
	Unite::mapT m;
	for(int i = 0; i < 12; i++) m[i] = NULL;
	return m;
}

Unite::mapT Unite::plateau = creerMap();

Unite* Unite::getUnite(int ind)
{
	mapT::iterator it = plateau.find(ind);
	return it->second;
}

void Unite::setUnite(int ind, Unite *u)
{
	plateau[ind] = u;
}
