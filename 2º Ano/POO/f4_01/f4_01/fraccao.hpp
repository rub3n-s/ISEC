//
//  fraccao.hpp
//  f4_01
//
//  Created by rsantos on 12/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef fraccao_hpp
#define fraccao_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Fraccao {
    int numerador;
    int denominador;
    
public:
    Fraccao(int num = 0, int den = 1);
    Fraccao operator*(const Fraccao &f);
    Fraccao &operator++();
    
    int getNumerador() const { return numerador; }
    int getDenominador() const { return denominador; }
    void setNumerador(int n) { numerador = n; }
    bool setDenominador(int d);
};

bool operator*(const Fraccao &a, const Fraccao &f);
Fraccao operator==(const Fraccao &a, const Fraccao &f);
ostream &operator<<(ostream &os, Fraccao f);
#endif /* fraccao_hpp */
