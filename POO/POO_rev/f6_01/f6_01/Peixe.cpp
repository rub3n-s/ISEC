//
//  Peixe.cpp
//  f6_01
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Peixe.hpp"
#include "Aquario.hpp"
#include <sstream>

unsigned int Peixe::conta = 500;

double getRealUniform();

Peixe::Peixe(string es, string c) : especie(es), cor(c), numSerie(conta++) {
    peso = 10;
}

string Peixe::getAsString() const {
    ostringstream os;
    os << "num: "<< numSerie << ", nome: " << especie << ", cor: " << cor << ", peso: " << peso << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const Peixe &p) {
    os << p.getAsString();
    return os;
}
    
bool Peixe::ligaAaquario(Aquario *a) {
    if (aquario != nullptr || a == nullptr)
        return false;
    aquario = a;
    return false;
}

bool Peixe::desligaAquario(Aquario *a) {
    if (aquario != a)
        return false;
    aquario = nullptr;
    return true;
}

Peixe::Peixe(Peixe &p) {
    especie = p.especie;
    cor = p.cor;
    especie = p.especie;
    peso = p.peso;
    numSerie = p.numSerie;
    indigestao = p.indigestao;
    resta = p.resta;
    
    if (p.aquario != nullptr)
        p.aquario->addPeixe(this);
    else
    p.aquario = nullptr;
}
