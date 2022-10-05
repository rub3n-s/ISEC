//
//  Equipa2.cpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Equipa2.hpp"
#include <sstream>
#include <iostream>

Equipa::Equipa() : pos(0) {
    for (unsigned int i = 0; i < 11; ++i)
        jogadores[i] = NULL;
    cout << "a construir..." << endl;
}

Equipa::~Equipa() {
    cout << "a destruir..." << endl;
}

void Equipa::setJogador(Pessoa *p) {
    jogadores[pos] = p;
    ++pos;
}

string Equipa::getAsString() const {
    ostringstream os;
    if (*jogadores == nullptr)
        os << "equipa sem jogadores.\n";
    else {
        os << "jogadores: \n";
        for (int i = 0; i < 11; ++i)
            if (jogadores[i] != NULL)
                os << "pos: " << i << ", " << jogadores[i]->getAsString();
    }
    return os.str();
}

Equipa::Equipa(const Equipa &e) {
    for (int i = 0; i < 11; ++i)
        jogadores[i] = e.jogadores[i];
}

Equipa &Equipa::operator=(const Equipa &e) {
    if (this == &e)
        return *this;
    
    delete jogadores[11];
    for (int i = 0; i < 11; ++i)
        jogadores[i] = NULL;
    
    for (int i = 0; i < 11; ++i)
        jogadores[i] = e.jogadores[i];
    return *this;
}

ostream &operator<<(ostream &os, const Equipa &e) {
    os << e.getAsString();
    return os;
}

