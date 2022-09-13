#include <sstream>
#include "Tarifario.h"

ostream &operator<<(ostream &os, const Tarifario &t)
{
	os << t.getAsString();
	return os;
}

Tarifario::Tarifario(double cm, double lb) 
	: carregaMin(cm), limiarBonus(lb)
{
	if (carregaMin < 0)
		carregaMin = 0;
	if (limiarBonus < 0)
		limiarBonus = 0;
}

string Tarifario::getAsString() const
{
	ostringstream os;
	os << " carregamento minimo " << carregaMin;
	os << " bonus a partir de " << limiarBonus;
	return os.str();
}
