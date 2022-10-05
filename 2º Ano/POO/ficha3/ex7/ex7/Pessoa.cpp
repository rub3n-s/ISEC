//
//  Pessoa.cpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#include "Pessoa.hpp"

Pessoa::Pessoa(int id, string n) : bi(id), nome(n) {}

string Pessoa::getNome() const { return nome; }
void Pessoa::setNome(string n) { nome = n; }
int Pessoa::getBI() const { return bi; }
