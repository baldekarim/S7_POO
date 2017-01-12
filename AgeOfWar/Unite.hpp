
#ifndef Unite_hpp
#define Unite_hpp
#include <iostream>
#include <string>
#include <map>

class Unite
{
	
  private :
	
	int prix;
	int ptsVie;
	int ptsAttaque;
	int portee;
	int numeroCase;
	char sensDeplacement;
	static bool init;
	
  public:
	
	typedef std::map<int, Unite*> mapT;
	static mapT plateau;
	
	Unite() {}
	Unite(int p, int v, int a, int por);
	
	virtual ~Unite() {};
	
	virtual std::string getClasse() const = 0;
	
	void setNumeroCase(int n, char sens) {
		numeroCase = n;
		sensDeplacement = sens;
	}
	
	void avancer();
	
	virtual void attaquer() = 0;
	
	bool action1();
	
	void action2();
	
	virtual void action3();
	
	static Unite* getUnite(int ind);
	
	static void setUnite(int ind, Unite *u);
	
	static mapT creerMap();
	
};

#endif
