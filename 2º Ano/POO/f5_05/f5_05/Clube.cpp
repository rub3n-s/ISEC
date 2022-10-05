//
//  Clube.cpp
//  f5_05
//
//  Created by rsantos on 24/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "Clube.hpp"

Clube::Clube(unsigned int t) : tam(t) {
    if (tam < 1)
        tam = 1;
    
    socios = new Pessoa* [tam];
    
    for (unsigned int i = 0; i < tam; i++) {
        socios[i] = nullptr;
    }
}

bool Clube::setMembroDoClube(Pessoa *p) {
    if (nSocios == tam)
        return false;
    
    socios[nSocios] = p;
    ++nSocios;
    
    return true;
}

string Clube::getAsString() const {
    ostringstream os;
    os << "Capacidade: " << tam << ",n. de socios: " << nSocios << "\n";
    
    for (unsigned i = 0; i < nSocios; i++)
        os << " " << *socios[i] << "\n";
    
    return os.str();
}

Clube &Clube::operator=(const Clube &r) {
    this->tam = r.tam;
    this->nSocios = r.nSocios;
    Pessoa **copia = new Pessoa* [tam];
    
    for(unsigned i = 0; i < tam; i++)
        copia[i] = r.socios[i];
    
    if(socios)
        delete[] socios;
    
    this->socios = copia;
    
    return *this;
}

Clube::~Clube() {
    if(socios)
        delete[] socios;
}

Clube::Clube(const Clube &r) {
    socios = nullptr;
    *this = r;
}
