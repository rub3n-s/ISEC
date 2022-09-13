#ifndef BANCO_H
#define BANCO_H
#include <vector>
#include "conta.h"
class Banco
{
	string nome;
	std::vector<Conta> contas;
public:
	Banco(string no) : nome(no) {}
	string getAsString() const;

	bool addConta(Conta c);
	bool delConta(const string &bi);
	bool deposita(const string &bi, int quantia);
};
#endif;
