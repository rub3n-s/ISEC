#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using std::string;
class Pessoa
{
	string nome;
	string nCC;	//número de cartão de cidadão
	int NIF; //número de comtribuinte
public:
	Pessoa(string no, string bi, int nc) : nome(no), nCC(bi), NIF(nc) {}

	string getAsString() const;
	string getCC() const { return nCC; }

	bool setNome(string nn);
};
#endif
