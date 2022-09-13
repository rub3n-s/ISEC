//
//  Desenho.cpp
//  f3_01
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Desenho.hpp"
#include <iostream>
#include <sstream>

Desenho::Desenho(string n) : nome(n) { }

bool Desenho::addFigura(Retangulo r) {
    this->figuras.push_back(r);
    cout << r.getAsString() << endl;
    return true;
}

string Desenho::getAsString() const {
    ostringstream os;
    os << "Desenho: " << this->nome;
    
    if (this->figuras.empty())
        os << ", em branco.";
    else {
        os << ", com: ";
        for (auto r: this->figuras)
            os << "\n" << r.getAsString();
    }
    
    return os.str();
}

double Desenho::somaAreas() {
    double soma = 0.0;
    for (auto r: figuras)
        soma += r.area();
    return soma;
}

void Desenho::removeAreaMaior(double a) {
    auto i = this->figuras.begin();
    while (i != this->figuras.end()) {
        if (i->area() > a)
            this->figuras.erase(i);
        else
            ++i;
    }
}
