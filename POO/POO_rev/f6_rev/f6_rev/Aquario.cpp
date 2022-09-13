//
//  Aquario.cpp
//  f6_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Aquario.hpp"
#include <iostream>
#include <sstream>

/*Aquario::Aquario(int t) : tam(t), nPeixes(0) {
    peixes = new Peixe * [tam];
    for (unsigned int i = 0; i < tam; ++i)
        peixes[i] = NULL;
} */

void Aquario::encontraPeixe(int numSerie) {
    /*for (int i = 0; i < nPeixes; ++i) {
        if (peixes[i]->getNSerie() == numS)
            cout << peixes[i]->getAsString();
    } */
    for (auto p : peixes) {
        if (p->getNSerie() == numSerie)
            cout << p->getAsString();
    }
}

bool Aquario::addPeixe(Peixe *p) {
    /*Peixe * * aux = new Peixe * [tam+1];
    
    for (int i = 0; i < nPeixes; ++i)
        aux[i] = peixes[i];
    
    aux[nPeixes] = p;
    ++nPeixes;
    delete[] peixes;
    peixes = aux; */
    
    if (p == nullptr)
        return false;
    if (p->ligaAaquario(this) == false)
        return false;
    
    peixes.push_back(p);
    return true;
}

void Aquario::selfClean() {
    auto i = peixes.begin();
    while (i != peixes.end()) {
        if ((*i)->isVivo())
            ++i;
        else
            peixes.erase(i);
    }
}

Peixe *Aquario::eliminaPeixe(int numSerie) {
    auto i = peixes.begin();
    while(i != peixes.end()) {
        if ((*i)->getNSerie() == numSerie) {
            Peixe *out = *i;
            peixes.erase(i);
            
            /*if ((*it)->desligaAquario(this) == false)
                    return nullptr; */
            return out;
        }
        else
            ++i;
    }
    
    return nullptr;
}

void Aquario::alimentarPeixes(int g) {
    for (auto p : peixes)
        p->come(g);
}

string Aquario::getAsString() const {
    ostringstream os;
    for (auto p : peixes)
        os << p->getAsString();
    return os.str();
}

ostream &operator<<(ostream &os, const Aquario &a) {
    os << a.getAsString();
    return os;
}

    
