//
//  Conta.cpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#include "Conta.hpp"

Conta::Conta(Pessoa tit, int s) : titular(tit), saldo(s) {}

Conta::Conta(Pessoa tit) : titular(tit) {
    saldo = 0;
}

string Conta::getTitular() const { return titular.getNome(); }
void Conta::setNomeTitular(string nome) { titular.setNome(nome); }
int Conta::getBI() const { return titular.getBI(); }
int Conta::getSaldo() const { return saldo; }
void Conta::aumentarSaldo(int s) { saldo+=s; }
void Conta::diminuirSaldo(int s) {
    saldo-=s;
    if (saldo < 0)
        saldo = 0;
}
