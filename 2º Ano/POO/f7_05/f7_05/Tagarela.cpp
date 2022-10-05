#include <sstream>
#include "Tagarela.h"

Tagarela::Tagarela(double c1m, double cms, double b, double carrMin, double limBon)
	: Tarifario(carrMin, limBon), custo1min(c1m), custoMinSeg(cms), bonus(b)
{
	if (custo1min < 0)
		custo1min = 0;
	if (custoMinSeg < 0)
		custoMinSeg = 0;
	if (bonus < 0)
		bonus = 0;
}

bool Tagarela::autorizaChamada(double saldo)
{
	return saldo > (-1)*custo1min;
}

double Tagarela::custoChamada(int duracao)
{
	if ( duracao < 0)
		return 0.0;
	if (duracao == 0)
		return custo1min;
	int minutos = duracao / 60;
	if (duracao % 60 > 0)
		++minutos;
	return custo1min + (minutos - 1) * custoMinSeg;
}

double Tagarela::carrega(double quantia)
{
	if (quantia < getCarregaMin())
		return 0.0;
	if (quantia < getLimiarBonus())
		return quantia;
	return quantia + bonus;
}

string Tagarela::getAsString() const
{
	ostringstream os;
	os << Tarifario::getAsString();
	os << " valor do bonus " << bonus;
	os << " custo primeiro minuto " << custo1min;
	os << " custo minutos seguintes " << custoMinSeg;
	return os.str();
}

ostream &operator<<(ostream &os, const Tagarela &t)
{
	os << t.getAsString();
	return os;
}
