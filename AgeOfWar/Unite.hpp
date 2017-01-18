
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
	char sensDeplacement;
	static bool init;
	
	protected:
	int numeroCase;
	Unite *cible;
	bool attack;
	int position;
	
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
	
	bool getEnnemi(Unite *cible);
	
	virtual void attaquer() = 0;
	
	bool action1();
	
	void action2();
	
	virtual void action3();
	
	int getPtsVie(){
		return ptsVie;
		};
	int getPtsAttaque(){
		return ptsAttaque;
	};
	
	void setPtsVie(int vie);
	
	static Unite* getUnite(int ind);
	
	static void setUnite(int ind, Unite *u);
	
	static mapT creerMap();
	
	//SURCHARGE
	friend std::ostream &operator << (std::ostream &os, const Unite &u); 
};

#endif
