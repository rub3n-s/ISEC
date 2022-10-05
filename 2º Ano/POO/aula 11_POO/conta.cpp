#include <sstream>
#include "conta.h"

bool Conta::levanta(int quantia) {
	if (quantia < 0 || quantia > saldo)
		return false;
	saldo -= quantia;
	return true;
}
bool Conta::deposita(int quantia) {
	if (quantia < 0)
		return false;
	saldo += quantia;
	return true;
}
string Conta::getAsString() const {
	std::ostringstream os;
	os << titular->getAsString() << ", saldo: " << saldo;
	return os.str();
}

