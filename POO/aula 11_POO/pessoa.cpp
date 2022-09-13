#include <sstream>
#include "pessoa.h"

string Pessoa::getAsString() const {
	std::ostringstream os;
	os << nome << ", cartao cidadao: " << nCC << ", n contribuinte: " << NIF;
	return os.str();
}
//FALTA: verificar se o nome é válido
bool Pessoa::setNome(string nn) {
	nome = nn;
	return true;
}
