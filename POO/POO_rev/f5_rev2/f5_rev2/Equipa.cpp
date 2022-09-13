//
//  Equipa.cpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Equipa.hpp"
#include <sstream>

Equipa::Equipa() : pos (0) {
    for (unsigned int i=0; i<11; i++)
        jogadores[i]= NULL;
}

Equipa::Equipa(const Equipa &e) {
    if (this == &e)
        return;
    
    Pessoa * aux[11];
    
    for (int i = 0; i < 11; ++i)
        aux[i] = e.jogadores[i];
    
    delete *jogadores;
    pos = e.pos;
    *jogadores = *aux;
}

Equipa &Equipa::operator=(const Equipa &e) {
    if (this == &e)
        return *this;
    
    pos = e.pos;
    Pessoa * aux[11];
    
    for (int i = 0; i < 11; ++i)
        aux[i] = e.jogadores[i];
    
    delete *jogadores;
    *jogadores = *aux;
    return *this;
}

bool Equipa::setJogador(Pessoa * p) {
    /*if (pos < 0 || pos > 10)
        return false;
    jogadores[pos] = p;
    return true; */
    
    if (p == nullptr)
        return false;
    
    jogadores[pos] = p;
    p++;
    return true;
}

string Equipa::getAsString() const {
    ostringstream os;
    for (auto j : jogadores)
        os << *j << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const Equipa &e) {
    os << e.getAsString();
    return os;
}
