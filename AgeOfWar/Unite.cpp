
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
	action1Effectuee = false;
}

// GESTION DES ACTIONS POSSIBLES

void Unite::action1()
{
	if(attaquer()) action1Effectuee = true;
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

ostream &operator << (ostream &os, const Unite &u) {
	return os << "\tType : " << u.getClasse() << "   Prix : " <<u.prix<<"\n\t\t\tPoints de Vie : " <<u.ptsVie<<"\n\t\t\tPoints d'attaque : " <<u.ptsAttaque<<"\n\t\t\tPortée maximale : "<<u.portee<< "\n\t\t\tNuméro de case : "<<u.numeroCase<<endl;
}
