//
//  peixe.cpp
//  f6_01
//
//  Created by rsantos on 10/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <stdio.h>
#include "peixe.h"
#include "aquario.h"

unsigned int Peixe::conta = 500;

double getRealUniform();

Peixe::Peixe(string es, string co) : especie(es), cor(co), numSerie(conta++) {
    peso = 10;
}

string Peixe::getAsString() const {
    ostringstream os;
    os << "n serie: " << numSerie << ", especie: " << especie << ", cor: "<< cor << ", peso: " << peso;
    return  os.str();
}

ostream &operator<<(ostream &os, const Peixe &p) {
    os << p.getAsString();
    return os;
}

bool Peixe::ligaAaquario(Aquario *a) {
    if (aquario != nullptr || a == nullptr)
        return false;
    aquario = a;
    return true;        
}

void Peixe::come(unsigned int c) {
    if (indigestao) {
        if (resta > 0)
            --resta;
        return;
    }
    
    peso += c;
    if (peso > 50) {
        if (getRealUniform() < 0.5) {
            Peixe *peixinho = new Peixe(especie + "D", cor);
            aquario->addPeixe(peixinho);
            peso = 40;
        }
        else {
            indigestao = true;
            peso /= 2;
        }
    }
}

bool Peixe::desligaAquario(Aquario *a) {
    if (aquario != a)
        return false;
    
    aquario = nullptr;
    return true;
}

bool Peixe::setPeso(int g) {
    if (g < 0)
        return false;
    
    peso = g;
    return true;
}

Peixe::Peixe(const Peixe &p) {
    numSerie = p.numSerie;
    cor = p.cor;
    especie = p.especie;
    peso = p.peso;
    indigestao = p.indigestao;
    resta = p.resta;
    
    if (p.aquario != nullptr)
        p.aquario->addPeixe(this);
    else
        p.aquario = nullptr;
}
