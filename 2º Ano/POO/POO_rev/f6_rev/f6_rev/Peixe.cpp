//
//  Peixe.cpp
//  f6_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Peixe.hpp"
#include "Aquario.hpp"
#include <sstream>

double getRealUniform();

unsigned int Peixe::conta = 500;

Peixe::Peixe(string e, string c) : especie(e), cor(c), nSerie(conta++) {
    peso = 10;
}

Peixe::Peixe(const Peixe &p) {
    especie = p.especie;
    cor = p.cor;
    peso = p.peso;
    nSerie = p.nSerie;
}

bool Peixe::ligaAaquario(Aquario *a) {
    if (a == nullptr || aquario != nullptr)
        return false;
    aquario = a;
    return true;
}

void Peixe::come(int g) {
    if (indigestao)
        if (resta > 0)
            --resta;
    
    peso+=g;
    if (peso > 50) {
        if (getRealUniform() < 0.5) {
            peso -= 40;
            Peixe *novo = new Peixe(especie + "D", cor);
            aquario->addPeixe(novo);
        }
        else {
            peso/=2;
            indigestao = true;
        }
    }
}

bool Peixe::isVivo() {
    if (indigestao)
        return false;
    
    return true;
}

string Peixe::getAsString() const {
    ostringstream os;
    os << "num: " << nSerie << ", especie: " << especie << ", cor: " << cor << ", peso: " << peso << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const Peixe &p) {
    os << p.getAsString();
    return os;
}
