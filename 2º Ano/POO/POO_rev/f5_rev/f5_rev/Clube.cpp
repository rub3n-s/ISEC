//
//  Clube.cpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Clube.hpp"
#include <sstream>

Clube::Clube(int t) {
    if (tam <= 0)
        tam = 1;
    tam = t;
    socios = new Pessoa * [tam];
    for (unsigned int i=0; i<tam; i++)
        socios[i]= NULL;
}

Clube::~Clube() {
    if (socios)
        delete [] socios;
}

Clube::Clube(const Clube &c) : socios(nullptr), tam(c.tam) {
    Pessoa * * aux = new Pessoa * [tam];
    
    if (c.socios == nullptr || c.tam == 0) {
        socios = nullptr;
        return;
    }
    
    for (int i = 0; i < tam; ++i)
        aux[i] = c.socios[i];
    socios = aux;
}

Clube &Clube::operator=(const Clube &c) {
    Pessoa * * aux = new Pessoa * [c.tam];
    
    tam = c.tam;
    
    if (c.socios == nullptr || c.tam == 0) {
        socios = nullptr;
        return *this;
    }
    
    for (int i = 0; i < tam; ++i)
        aux[i] = c.socios[i];
    socios = aux;
    return *this;
}

string Clube::getAsString() const {
    ostringstream os;
    for (int i = 0; i < tam; ++i)
        if (socios[i] != NULL)
            os << *socios[i];
    return os.str();
}

ostream &operator<<(ostream &os, const Clube &c) {
    os << c.getAsString();
    return os;
}
