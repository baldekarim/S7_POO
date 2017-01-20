
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
	
  protected :
	
	int numeroCase;
	bool action1Effectuee;
	
  public:
	
	typedef std::map<int, Unite*> mapT;
	static mapT plateau;
	
	Unite() {}
	Unite(int, int, int, int);
	
	virtual ~Unite() {};
	
	virtual std::string getClasse() const = 0;
	
	void setNumeroCase(int n, char sens) {
		numeroCase = n;
		sensDeplacement = sens;
	}
	
	int getNumeroCase() const { return numeroCase; }
	
	void avancer();
	
	virtual bool attaquer() = 0;
	
	void action1();
	
	void action2();
	
	virtual void action3();
	
	int getPtsVie()
	{
		return ptsVie;
	}
	
	int getPtsAttaque()
	{
		return ptsAttaque;
	}
	
	char getSensDeplacement()
	{
		return sensDeplacement;
	}
	
	void setPtsVie(int vie)
	{
		ptsVie = vie;
	}
	
	static Unite* getUnite(int);
	
	static void setUnite(int, Unite*);
	
	static mapT creerMap();
	
	friend std::ostream &operator << (std::ostream &os, const Unite &u);
	
};

#endif
