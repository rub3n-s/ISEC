#pragma once
#include <iostream>
#include <initializer_list>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Territorio {
	string nome;                   //nome do territorio
	int resistencia;               //for�a de luta contra invasores
	vector <int> criaProdutos;     //quantos produtos cria por turno
	vector <int> criaOuro;         //quanto ouro gera por turno
	int pontosVit;                 //quantos ponto d� por conquista

public:
	Territorio(string n,int id, int r, initializer_list<int> cP, initializer_list<int> cO,int pV);
	string getNome();

};