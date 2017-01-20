
#ifndef Singleton_hpp
#define Singleton_hpp
#include <iostream>

template <typename T>
class Singleton
{
	
  private:
	// Instance unique
	static T *singleton;
	
  protected:
	// Constructeur/destructeur du singleton
	Singleton () {}
	~Singleton ()
	{
		std::cout << "\t\t**************************************************"<<std::endl;
		std::cout << "\t\t*         Destruction du singleton : jeu         *"<<std::endl;
		std::cout << "\t\t**************************************************\n"<<std::endl;
	}
	
  public:
	
	static T *getInstance ()
	{
		if (singleton == NULL)
		{
			std::cout << "\t\t**************************************************"<<std::endl;
			std::cout << "\t\t*      Création du singleton : jeu               *"<<std::endl;
			std::cout << "\t\t**************************************************\n"<<std::endl;
			singleton = new T;
		}
		return (static_cast<T*> (singleton));
	}
	
	static void kill ()
	{
		if (singleton != NULL)
		{
			delete singleton;
			singleton = NULL;
		}
	}
	
};

// On initialise le singleton à NULL
template <typename T>
T *Singleton<T>::singleton = NULL;

#endif
