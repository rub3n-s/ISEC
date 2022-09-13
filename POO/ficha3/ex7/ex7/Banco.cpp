//
//  Banco.cpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#include "Banco.hpp"

Banco::Banco(string n) : nome(n) {}

void Banco::recebeConta(Conta c) {
    contas.push_back(c);
}

void Banco::encontraConta(int bi) {
    for (auto c : contas)
        if (c.getBI() == bi)
            cout << c.getTitular() << endl;
}

void Banco::eliminaConta(int bi) {
    int i = 0;
    for (auto c : contas){
        if (c.getBI() == bi)
            contas.erase(contas.begin()+i);
        i++;
    }
}

void Banco::depositar(int bi, int valor) {
    for (auto c : contas) {
        if (c.getBI() == bi)
            c.aumentarSaldo(valor);
    }
}

int Banco::obterSoma() const {
    int soma = 0;
    for (auto c : contas)
        soma += c.getSaldo();
    return soma;
}

string Banco::getAsString() const {
    ostringstream os;
    os << "Banco: " << nome;
    os << ", com os titulares: " << endl;
    for (auto c : contas)
        os << "\tbi: " << c.getBI() << ", nome: " << c.getTitular() << ", saldo: " << c.getSaldo() << endl;
    return os.str();
}
