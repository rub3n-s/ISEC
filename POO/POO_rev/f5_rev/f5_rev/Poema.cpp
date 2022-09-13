//
//  Poema.cpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Poema.hpp"
#include <sstream>
#include <iostream>

Poema::Poema(string t) : titulo(t), nVersos(0), pVersos(nullptr) { }

Poema::Poema(const Poema &p) : titulo(p.titulo), nVersos(p.nVersos){
    if (p.nVersos == 0 || p.pVersos == nullptr) {
        pVersos = nullptr;
        return;
    }
    
    pVersos = new string[p.nVersos];
    
    for (int i = 0; i < nVersos; ++i)
        pVersos[i] = p.pVersos[i];
}

Poema::~Poema() {
    delete [] pVersos;
}

Poema &Poema::operator=(const Poema &p) {
    if (this == &p)
        return *this;
    
    titulo = p.titulo;
    nVersos = p.nVersos;
    
    delete []pVersos;
    pVersos = nullptr;
    
    if (p.nVersos == 0 || p.pVersos == nullptr) {
        pVersos = nullptr;
        return *this;
    }
    
    pVersos = new string[p.nVersos];
    
    for (int i = 0; i < nVersos; ++i)
        pVersos[i] = p.pVersos[i];
    
    return *this;
}

void Poema::acrescentaVerso(const string &verso) {
    string * aux = new string[nVersos + 1];
    for (int i = 0; i < nVersos; ++i)
        aux[i] = pVersos[i];
    aux[nVersos] = verso;
    
    ++nVersos;
    delete [] pVersos;
    pVersos = aux;
}

void Poema::eliminaVerso(int pos) {
    if (pos < 0 || pos >= nVersos)
        return;
    
    if (nVersos == 1) {
        delete[] pVersos;
        pVersos = nullptr;
        nVersos = 0;
        return;
    } else if (nVersos == 0)
        cout << "Não existem versos no poema\n";
    
    string * aux = new string[nVersos - 1];
    
    for (int i = 0; i < pos; ++i)
        aux[i] = pVersos[i];
    
    for (int i = pos; i < nVersos - 1; ++i)
        aux[i] = pVersos[i + 1];
    
    --nVersos;
    delete[] pVersos;
    pVersos = aux;
}

string Poema::getAsString() const {
    ostringstream os;
    os << "titulo: " << titulo;
    if (nVersos == 0)
        os << ", sem versos!\n";
    else {
        os << ", com os versos: \n";
        for (int i = 0; i < nVersos; ++i)
            os << pVersos[i] << endl;
    }
    return os.str();
}

ostream &operator<<(ostream &os, const Poema &p) {
    os << p.getAsString();
    return os;
}
