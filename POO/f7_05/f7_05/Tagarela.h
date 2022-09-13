#ifndef TAGARELA_H
#define TAGARELA_H

#include "Tarifario.h"
class Tagarela : public Tarifario
{
	double custo1min;	//custo do primeiro minuto
	double custoMinSeg; //custo de cada minuto seguinte
	double bonus;	//valor do bónus
public:
	Tagarela(double c1m = 0.5, double cms = 0.02, double b = 5,
		double carrMin = 25, double limBon = 50);

	virtual bool autorizaChamada(double saldo) override;
	virtual double custoChamada(int duracao) override;
	virtual double carrega(double quantia) override;
    virtual Tagarela *clone() const override { return new Tagarela(*this); }
    virtual string getNome() const override { return "tagarela"; }
    
	virtual string getAsString() const override;

	virtual ~Tagarela() {}
};
ostream &operator<<(ostream &os, const Tagarela &t);

#endif // !TAGARELA_H


