//
//  Equipa.cpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Equipa.hpp"
#include <sstream>
#include <iostream>

EquipaFutebol::EquipaFutebol() {
    for (unsigned int i = 0; i < 11; i++)   // inicialmente equipa vazia
        jogadores[i]= NULL;             // NULL significa sem jogador
}

EquipaFutebol::~EquipaFutebol() {
    for (auto j : jogadores) {
        if (j != nullptr) {
            cout << "a destruir..." << j->getAsString();
            j = nullptr;
        }
    }    
}

void EquipaFutebol::setJogador(Pessoa *p, int pos) {
    jogadores[pos] = p;
}

string EquipaFutebol::getAsString() const {
    ostringstream os;
    os << "Jogadores: " << endl;
    for (int i = 0; i < 11; ++i)
        if (jogadores[i] != NULL)
            os << jogadores[i]->getAsString();
    return os.str();
}

ostream &operator<<(ostream &os, const EquipaFutebol &e) {
    os << e.getAsString();
    return os;
}
