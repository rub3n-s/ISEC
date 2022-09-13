#pragma once
#pragma once

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <initializer_list>

#include "Mundo.h"

using namespace std;

class Comando {
	Mundo * mundo;
public:
	Comando(Mundo & mundo);
	bool verificaCmd(string m);
	bool verificaCon(string c);
	bool verificaInt(string in,int &cri);
    void configuracao();
	bool criaCmd(istringstream & iss);
	bool carregaFicheiro(string f);

};