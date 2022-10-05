//
//  Banco.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Banco.hpp"
#include <sstream>

Banco::Banco(string n) : nome(n) {}

void Banco::addConta(Conta c) {
    contas.push_back(c);
}

string Banco::getAsString() const {
    ostringstream os;
    os << "Banco: " << nome;
    if (contas.empty())
        os << ", sem contas!";
    else {
        os << ", com as contas: \n";
        for (auto c : contas)
            os << c.getAsString();
    }
    return os.str();
}

bool Banco::depositar(int bi, int valor) {
    auto i = this->contas.begin();
    if (valor < 0)
        return false;
    while(i != this->contas.end()) {
        if (i->getBI() == bi)
            i->aumentaSaldo(valor);
        else
            ++i;
    }
    return true;
}

bool Banco::levantar(int bi, int valor) {
    auto i = this->contas.begin();
    if (valor < 0)
        return false;
    while(i != this->contas.end()) {
        if (i->getBI() == bi) {
            if (i->getSaldo() < valor)
                return false;
            else
                i->diminuiSaldo(valor);
        }
        else
            ++i;
    }
    return true;
}

int Banco::somaSaldos() {
    int soma = 0;
    for (auto c : contas)
        soma += c.getSaldo();
    return soma;
}

void Banco::eliminarConta(int bi) {
    auto i = this->contas.begin();
    while(i != this-> contas.end()) {
        if (i->getBI() == bi)
            contas.erase(i);
        else
            ++i;
    }
}
