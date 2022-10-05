#include "Territorio.h"

Territorio::Territorio(string n, int id, int r, initializer_list<int> cP, initializer_list<int> cO, int pV) {
	ostringstream oss;
	oss << n << id;
	nome = oss.str();
	resistencia = r;
	criaProdutos = cP;
	criaOuro = cO;
	pontosVit = pV;

}

string Territorio::getNome() {
	return nome;
}