//
//  tarifario.cpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <sstream>
#include "tarifario.hpp"

Tarifario::Tarifario(const Tarifario &f) {
    *this = f;
}

Tarifario &Tarifario::operator=(const Tarifario &t) {
    if (this == &t)
        return *this;
    int *novo = nullptr;
    if (t.duracoes) {
        novo = new int [t.nTreinos];
        for (size_t i = 0; i < nTreinos; ++i)
            novo[i] = t.duracoes[i];
    }
    nTreinos = t.nTreinos;
    delete [] duracoes;
    duracoes = novo;
    return *this;
}


void Tarifario::apagaTreinos() {
    if (duracoes) {
        delete [] duracoes;
        duracoes = nullptr;
        nTreinos = 0;
    }
}

int Tarifario::getDuracoesTreinosI(size_t i) {
    if (i < 0 || i >= nTreinos)
        return 0;
    return duracoes[i];
}

bool Tarifario::acrescentaTreinos(int dur) {
    if (dur < 0)
        return false;
    
    int *novo = new int[nTreinos + 1];
    for (size_t i = 0; i < nTreinos; ++i)
        novo[i] = duracoes[i];
    novo[nTreinos] = dur;
    ++nTreinos;
    delete [] duracoes;
    duracoes = novo;
    return true;
}

string Tarifario::getAsString() const {
    ostringstream os;
    
    if (nTreinos == 0)
        os << "sem treinos a pagar";
    else {
        os << "duracao dos treinos a pagar: \n";
        for(size_t i = 0; i < nTreinos; i++)
            os << "" << duracoes[i] << "\n";
    }
    
    return os.str();
}

ostream &operator<<(ostream &os, const Tarifario &t) {
    os << t.getAsString();
    return os;
}


