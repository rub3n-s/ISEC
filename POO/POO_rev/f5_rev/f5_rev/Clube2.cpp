//
//  Clube2.cpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Clube2.hpp"
#include <sstream>

Clube::Clube(int t) : nSocios(0) {
    tam = t;
    socios = new Pessoa * [tam];
    for (unsigned int i = 0; i < tam; ++i)
        socios[i] = NULL;
}

Clube::Clube(const Clube &c) : socios(nullptr), tam(c.tam) {
    Pessoa * * aux = new Pessoa * [tam];
    
    if (c.nSocios == 0 || c.socios == nullptr) {
        nSocios = 0;
        socios = nullptr;
        return;
    }
        
    for (int i = 0; i < nSocios; ++i)
        aux[i] = c.socios[i];
    socios = aux;
}

Clube::~Clube() {
    delete [] socios;
}

Clube &Clube::operator=(const Clube &c) {
    Pessoa * * aux = new Pessoa * [tam];
    
    if (this == &c)
        return *this;
    
    if (c.socios == nullptr || c.nSocios == 0) {
        delete[] socios;
        socios = nullptr;
        nSocios = 0;
        return *this;
    }
        
    delete []socios;
    socios = nullptr;
    
    for (int i = 0; i < nSocios; ++i)
        aux[i] = c.socios[i];
    
    socios = aux;
    return *this;
}

void Clube::setMembroDoClube(Pessoa *p) {
    Pessoa * * aux = new Pessoa * [tam];
    
    for (int i = 0; i < nSocios; ++i)
        aux[i] = socios[i];
    aux[nSocios] = p;
    
    ++nSocios;
    delete[] socios;
    socios = aux;
}

string Clube::getAsString() const {
    ostringstream os;
    if (nSocios == 0)
        os << ", sem sócios\n";
    else {
        os << ", com os sócios: \n";
        for (int i = 0; i < nSocios; ++i)
            os << *socios[i];
    }
    return os.str();
}

ostream &operator<<(ostream &os, const Clube &c) {
    os << c.getAsString();
    return os;
}
