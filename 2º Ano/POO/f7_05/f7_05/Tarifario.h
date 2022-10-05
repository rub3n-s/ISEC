#ifndef TARIFARIO_H
#define TARIFARIO_H
#include <iostream>
#include <string>
using namespace std;
class Tarifario
{
	double carregaMin; //quantia m�nima poss�vel para fazer carregamento
	double limiarBonus; //valor m�nimo para poder atribuir b�nus
protected:
	double getCarregaMin() { return carregaMin; }
	double getLimiarBonus() { return limiarBonus; }
public:
	Tarifario(double cm, double lb);
	virtual bool autorizaChamada(double saldo) = 0;
	virtual double custoChamada(int duracao) = 0;
	virtual double carrega(double quantia) = 0;
    virtual Tarifario *clone() const = 0;
    virtual string getNome() const { return "tarifario"; }
	virtual string getAsString() const;
	virtual ~Tarifario() {}
};
ostream &operator<<(ostream &os, const Tarifario &t);
#endif // !TARIFARIO_H



