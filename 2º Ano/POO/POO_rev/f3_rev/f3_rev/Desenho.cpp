//
//  Desenho.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Desenho.hpp"
#include <sstream>

Desenho::Desenho(string n) : nome(n) {}

bool Desenho::addFigura(Retangulo r) {
    this->figuras.push_back(r);
    cout << r.getAsString();
    return true;
}

int Desenho::somaAreas() {
    double soma = 0;
    for (auto f : figuras)
        soma += f.area();
    return soma;
}

string Desenho::getAsString() const {
    ostringstream os;
    os << "Desenho: " << nome << endl;
    if (figuras.empty())
        os << ", em branco!" << endl;
    else {
        os << "com, " << endl;
        for (auto f : figuras)
            os << f.getAsString() << endl;
    }
    return os.str();
}

void Desenho::removeAreaMaior(int a) {
    for (auto f : figuras) {
        if (f.area() > a)
            figuras.clear();
    }        
}
