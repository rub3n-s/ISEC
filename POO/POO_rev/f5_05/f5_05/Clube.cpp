//
//  Clube.cpp
//  f5_05
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Clube.hpp"
#include <sstream>

Clube::Clube(unsigned int t) {
    if (tam <= 0)
        tam = 1;
    tam = t;
    socios = new Pessoa * [tam];
    for (unsigned int i=0; i<tam; i++)
        socios[i]= NULL;
}

Clube::Clube(const Clube &c) {
    socios = nullptr;
    *this = c;
}

Clube::~Clube() {
    if (socios)
        delete []socios;
}

bool Clube::setMembroDoClube(Pessoa * p) {
    if (nSocios == tam)
        return false;
    
    socios[nSocios] = p;
    ++nSocios;
    return true;
}

string Clube::getAsString() const {
    ostringstream os;
    os << "Capacidade: " << tam << ", n. de socios: " << nSocios << endl;
    for (unsigned int i = 0 ; i < nSocios; ++i)
        os << " " << *socios[i];
    return os.str();
}

ostream &operator<<(ostream &os, const Clube &c) {
    os << c.getAsString();
    return os;
}

Clube &Clube::operator=(const Clube &c) {
    this->tam = c.tam;
    this->nSocios = c.nSocios;
    Pessoa **copia = new Pessoa* [tam];
    
    for (unsigned int i = 0; i < tam; ++i)
        copia[i] = c.socios[i];
    
    if (socios)
        delete []socios;
    this->socios = copia;
    
    return *this;
}
