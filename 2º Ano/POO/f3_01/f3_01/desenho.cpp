//
//  desenho.cpp
//  f3_01
//
//  Created by rsantos on 03/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "desenho.hpp"
#include <sstream>

using namespace std;

string Desenho::getAsString() const {
    ostringstream os;
    os << "Desenho: " << this->nome;
    
    if (this->figuras.empty())
        os << ", em branco.";
    else {
        os << ", com: ";
        for (auto r: this->figuras)
            os << "\n " << r.getAsString();
    }
    
    return os.str();
}

bool Desenho::addFigura(Retangulo r) {
    this->figuras.push_back(r);
    cout << r.getAsString() << endl;
    
    return true;
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
