#ifndef CARTAO_H
#define CARTAO_H
#include <string>
#include "Tarifario.h"
using namespace std;

class Cartao
{
	int numero;
	double saldo = 0;
	Tarifario *tarifario = nullptr;
public:
	Cartao(int num, double sal = 0, Tarifario *t = nullptr)
		: numero(num), saldo(sal), tarifario(t) {}
	Cartao(const Cartao &) = default;
	Cartao &operator=(const Cartao &) = default;

	int getNumero()const { return numero; }
	bool autorizaChamada() const;
	bool registaChamada(int duracao);
	bool carrega(double quantia);
	bool adereTarifario(Tarifario *t);
    
    bool isTarifario(Tarifario *t) const { return t == tarifario; }
    string getNomeTarifario() { return tarifario->getNome(); }
    
    virtual Cartao *clone() const { return new Cartao(*this); }
	virtual string getAsString() const;
	virtual ~Cartao() = default;
};
ostream &operator<<(ostream &os, const Cartao &c);
#endif // !CARTAO_H



