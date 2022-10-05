//
//  ex9.cpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ex9.hpp"
#include <iostream>
#include <sstream>

Televisao::Televisao(vector<string> ca) {
    for(auto c : ca)
        canais.push_back(c);
}

void Televisao::aumentaSom() {
    if (ligada) {
        if (som == 10)
            cout << "O som já está no máximo!\n";
        som++;
    }
    else
        cout << "Tv desligada\n";
}

void Televisao::diminuiSom() {
    if (ligada) {
        if (som == 0)
            cout << "O som já está a zero!\n";
        som--;
    }
    else
        cout << "Tv desligada!\n";
}

string Televisao::getAsString() const {
    ostringstream os;
    
    if (ligada)
        os << "Tv ligada, ";
    else
        os << "Tv desligada, ";
    
    os << "no canal: " << canal << ", com os canais: ";
    for (auto c: canais)
        os << c << " ";
    
    os << ", som no volume: " << som << endl;
    
    return os.str();
}

void Televisao::ligaTV() {
    if (!ligada)
        ligada = true;
    else
        cout << "Tv já está ligada!\n";
}

void Televisao::desligaTV() {
    if (ligada)
        ligada = false;
    else
        cout << "Tv já está desligada!\n";
}

void Televisao::ligaCanal(int c) {
    if (ligada) {
        if (c <= 0 || c > N)
            canal = canais[0];
        canal = canais[c-1];
    }
    else
        cout << "Tv desligada, impossivel mudar de canal!\n";
}
