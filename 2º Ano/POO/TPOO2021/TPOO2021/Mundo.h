#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <initializer_list>
#include "Territorio.h"

class Mundo {
	vector <Territorio*> continente;
	vector <Territorio*> ilhas ;

public:
	Mundo();
	bool carregaFich(string fich);
	void contaContinente(string nome, int &aux);
	void contaIlha(string nome, int& aux);
	void recebeContinente(string continente,int num);
	void recebeIlha(string ilha, int num);
    void criaContinente(Territorio *t);
	void criaIlha(Territorio* t);
	string listaContinente()const;
	string listaIlha()const;
};