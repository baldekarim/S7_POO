
#include "Case.hpp"

using namespace std;

void Case::afficher(ostream &flux) const
{
	if(occupe)
		flux << "Case " << numero <<" est occupe "<<endl;
	else
		flux << "Case " << numero <<" est libre"<<endl;
}
