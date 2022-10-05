#include <sstream>
#include "banco.h"

string Banco::getAsString() const {
	std::ostringstream os;
	os << nome << " ";
	for (auto c : contas)
		os << "\n   " << c.getAsString();
	return os.str();
}

//FALTA: verificar se a conta é válida (por ex. BI único)
bool Banco::addConta(Conta c) {
	contas.push_back(c);
	return true;
}

bool Banco::deposita(const string &bi, int quantia) {
	for (auto &c : contas)
		if (c.getTitular()->getCC() == bi)
			return c.deposita(quantia);
	return false;
}

bool Banco::delConta(const string &bi) {
	std::vector<Conta>::iterator i;
	for (i = contas.begin(); i != contas.end(); i++) {
		if (i->getTitular()->getCC() == bi) {
			i = contas.erase(i);
			return true;
		}
	}
	return false;
}

