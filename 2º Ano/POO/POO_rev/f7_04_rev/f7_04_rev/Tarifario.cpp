//
//  Tarifario.cpp
//  f7_04_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Tarifario.hpp"
#include <sstream>

Tarifario::Tarifario(const Tarifario &t) {
    *this = t;
}

bool Tarifario::acrescentaTreino(int duracao) {
    if (duracao < 0)
        return false;
    
    int * aux = new int[nTreinos+1];
    
    for (size_t i = 0; i < nTreinos; ++i)
        aux[i] = duracoes[i];
    aux[nTreinos] = duracao;
    delete [] duracoes;
    duracoes = aux;
    return true;
}

Tarifario &Tarifario::operator=(const Tarifario &t) {
    if (this == &t)
        return *this;
    
    int * aux = nullptr;
    for (size_t i = 0; i < nTreinos; ++i)
        aux[i] = duracoes[i];
    nTreinos = t.nTreinos;
    delete []duracoes;
    duracoes = aux;
    return *this;
}

void Tarifario::apagaTreinos() {
    if (duracoes) {
        delete [] duracoes;
        duracoes = nullptr;
        nTreinos = 0;
    }
}

int Tarifario::getDuracaoTreinoI(size_t i) const {
    if (i < 0 || i > nTreinos)
        return false;
    
    cout << "treino: " << i << ", com duracao: " << duracoes[i];
    return true;
}

string Tarifario::getAsString() const {
    ostringstream os;
    if (nTreinos == 0)
        os << "sem treinos a pagar.\n";
    else {
        os << "treinos a pagar: \n";
        for (size_t i = 0; i < nTreinos; ++i)
            os << duracoes[i] << endl;
    }
    return os.str();
}

ostream &operator<<(ostream &os, const Tarifario &t) {
    os << t.getAsString();
    return os;
}
