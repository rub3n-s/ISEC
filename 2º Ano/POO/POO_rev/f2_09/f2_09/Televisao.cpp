//
//  Televisao.cpp
//  f2_09
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Televisao.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <initializer_list>

TV::TV(initializer_list<string> ca) : canais(ca) {
    int n = 0;
    
    if (n < MAX_CANAIS) {
        for (auto c : canais) {
            canais.push_back(c);
            n++;
        }
    }
    
    if (!canais.empty())
        canalAtual = 1;
}

string TV::getAsString() const {
    ostringstream os;
    
    if (ligada)
        os << "TV ligada, ";
    else
        os << "TV desligada, ";
    
    if (!canais.empty()) {
        os << "no canal " << canalAtual << ": "<< canais[canalAtual - 1] << ", ";
        os << "com som no nivel: " << som << ", ";
    }
    
    if (!canais.empty()) {
        os << "com os canais: ";
        for (auto c : canais)
            os << c << " ";
    }
        
    return os.str();
}

bool TV::liga() {
    if (!canais.empty()) {
        ligada = true;
        return true;
    }
    return false;
}

bool TV::desliga() { return ligada = false; }
