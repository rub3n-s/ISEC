//
//  Passeio.cpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Passeio.hpp"
#include <sstream>
#include <iostream>

Passeio::Passeio(Cidadao &c, string v, string d) : lider(c), vila(v), data(d) {}

void Passeio::setDestino(int v) {
    vila = v;
    auto i = participantes.begin();
    while (i != participantes.end()) {
        participantes. erase(i);
    }
}

string Passeio::getAsString() const {
    ostringstream os;
    os << "lider: " << lider.getNome();
    if (participantes.empty())
        os << ", sem participantes!\n";
    else {
        os << ", com os participantes: \n";
        for (auto p : participantes)
            os << p->getNome() << endl;
    }
    return os.str();
}

bool Passeio::associarParticipante(Cidadao *c) {
    if (c == nullptr)
        return false;
    participantes.push_back(c);
    return true;
}

void Passeio::desassociarParticipante(int bi) {
    auto i = participantes.begin();
    while (i != participantes.end()) {
        if((*i)->getBi() == bi)
            participantes.erase(i);
        else
            ++i;
    }
}

ostream &operator<<(ostream &os, const Passeio &p) {
    os << p.getAsString();
    return os;
}
