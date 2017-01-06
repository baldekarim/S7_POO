
#include <iostream>
#include "Jeu.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

	/*
	cout<<"Test u1 ?= u1 ";
	if(u1==u1) cout<<"OK"<<endl;
	else cout<<"KO"<<endl;
	
	cout<<"Test u1 ?= u2 ";
	if(u1==u2) cout<<"OK"<<endl;
	else cout<<"KO"<<endl;
	
	cout<<"Test u1 ?= u3 ";
	if(u1==u3) cout<<"OK"<<endl;
	else cout<<"KO"<<endl;
	
	cout<<"Test u2 ?= u3 ";
	if(u2==u3) cout<<"OK"<<endl;
	else cout<<"KO"<<endl;
	*/
	
	// pointeurs sur l'unique instance de la classe UniqueObject
	Jeu *jeu;
	// initialisation du pointeur
	jeu = Jeu::getInstance ();
	// lancement du jeu
	jeu->lancerJeu();
	// destruction de l'instance unique
	jeu->kill();
	
	return 0;
}
