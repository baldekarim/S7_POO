
#include "Catapulte.hpp"

using namespace std;

/* On attaque d'abord l'unité la plus proche et ensuite on vérifie si une autre unité
   se trouve à la case suivante pour l'attaquer à son tour
   si l'unité qui attaque se trouve à la case c et qu'elle se déplace de la gauche 
   vers la droite alors l'unité la plus proche peut se trouve à la case c+2 si elle se
   déplace de la droite vers la gauche elle sera alors à c-2
 */
bool Catapulte::attaquer()
{
	Unite* cible = ennemiAPortee();
	if(cible == NULL)
		return false;
	else
	{
		cible->setPtsVie(cible->getPtsVie() - this->getPtsAttaque());
		int n = this->getNumeroCase() - cible->getNumeroCase();
		if(n == 2)
			cible = Unite::getUnite(this->numeroCase - 3);
		else if(n == -2)
			cible = Unite::getUnite(this->numeroCase + 3);
		else if(n == 3)
			cible = Unite::getUnite(this->numeroCase - 4);
		else
			cible = Unite::getUnite(this->numeroCase - 3);
		if(cible != NULL)
		{
			cible->setPtsVie(cible->getPtsVie() - this->getPtsAttaque());
			cout<<"Votre Catapulte a attaqué deux unités"<<endl;
		}
		else cout<<"Votre Catapulte n'a attaqué qu'une seule unité"<<endl;
		
		return true;
	}
}


void Catapulte::action2()
{
	cout<<"Votre unité ne peut pas effectuer de deuxième action car c'est une Catapulte"<<endl;
}

/* On cherche la première unité la plus proche peu importe qu'elle soit ennemie
   ou alliée
 */
Unite* Catapulte::ennemiAPortee()
{
	Unite* u = NULL;
	int i = 2;
	do
	{
		u = Unite::getUnite(this->numeroCase + i);
		i++;
	} while (u == NULL || i <= 4);

	return u;
}

void Catapulte::action3()
{
	if(this->action1Effectuee)
	{
		cout <<"Votre Catapulte ne peut pas avancer car elle a attaquer dans ce tour !"<<endl;
	}
	else this->avancer();
	
	// On réinitialise la variable action1Effectuee pour le prochain tour
	this->action1Effectuee = false;
}

