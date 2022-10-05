#pragma once
#include <iostream>
#include <initializer_list>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Territorio {
	string nome;                   //nome do territorio
	int resistencia;               //força de luta contra invasores
	vector <int> criaProdutos;     //quantos produtos cria por turno
	vector <int> criaOuro;         //quanto ouro gera por turno
	int pontosVit;                 //quantos ponto dá por conquista

public:
	Territorio(string n,int id, int r, initializer_list<int> cP, initializer_list<int> cO,int pV);
	string getNome();

};