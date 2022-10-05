//
//  Clube.cpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Clube.hpp"


Clube::Clube(int t) {
    tam = t;
    socios = new Pessoa * [tam];
    for (unsigned int i=0; i<tam; i++)
        socios[i]= NULL;
}

Clube::Clube(const Clube &c) : socios(nullptr), tam(c.tam){
    Pessoa * * aux = new Pessoa * [tam];
    
    if (c.socios == nullptr || c.nSocios == 0) {
        nSocios = 0;
        socios = nullptr;
        return ;
    }
        
    nSocios = c.nSocios;
    for (int i = 0; i < c.nSocios; ++i)
        aux[i] = c.socios[i];
    socios = aux;
}

Clube &Clube::operator=(const Clube &c) {
    if (this == &c)
        return *this;
    
    if (c.socios == nullptr || c.nSocios == 0) {
        delete[] socios;
        socios = nullptr;
        nSocios = 0;
        return *this;
    }
    
    Pessoa * * aux = new Pessoa * [tam];
    
    nSocios = c.nSocios;
    delete [] socios;
    socios = nullptr;
    
    for (int i = 0; i < nSocios; ++i)
        aux[i] = c.socios[i];
    
    socios = aux;
    
    return *this;
}

Clube::~Clube() {
    delete [] socios;
}

bool Clube::setMembroDoClube(Pessoa * p) {    
    if (p == nullptr)
        return false;
    
    Pessoa * * aux = new Pessoa * [tam];
    
    for (int i = 0; i < nSocios; ++i)
        aux[i] = socios[i];
    aux[nSocios] = p;
    ++nSocios;
    delete [] socios;
    socios = aux;
    return true;
}

string Clube::getAsString() const {
    ostringstream os;
    for (int i = 0; i < nSocios; ++i)
        os << *socios[i];
    return os.str();
}

ostream &operator<<(ostream &os, const Clube &c) {
    os << c.getAsString();
    return os;
}
