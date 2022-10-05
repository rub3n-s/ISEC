//
//  Fraccao.hpp
//  f4_01
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Fraccao_hpp
#define Fraccao_hpp

#include <iostream>

using namespace std;

class Fraccao {
    int numerador;
    int denominador;
    
public:
    Fraccao(int num = 0, int den = 1);
    Fraccao operator*(const Fraccao &f);
    //Fraccao &operator++();
    Fraccao &operator+=(const Fraccao &a);
    
    void setNumerador(int num) { numerador = num; }
    bool setDenominador(int den);
    
    int getNumerador() const { return numerador; }
    int getDenominador() const { return denominador; }
};

Fraccao operator*(const Fraccao &a, const Fraccao &b);
Fraccao operator==(const Fraccao &a, const Fraccao &f);
ostream &operator<<(ostream &os, const Fraccao f);

#endif /* Fraccao_hpp */
