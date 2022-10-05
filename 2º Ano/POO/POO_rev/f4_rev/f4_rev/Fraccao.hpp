//
//  Fraccao.hpp
//  f4_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Fraccao_hpp
#define Fraccao_hpp
#include <iostream>
#include <string>

using namespace std;

class Fraccao {
    int numerador;
    int denominador;
    
public:
    Fraccao(int n = 0, int d = 1);
    
    Fraccao operator*(Fraccao &c);
    Fraccao &operator*=(const Fraccao &a);
    Fraccao &operator++();
    
    void setNum(int n) { numerador = n; }
    void setDen(int d) { denominador = d; }
    int getNum() const { return numerador; }
    int getDen() const { return denominador; }
    
    string getAsString() const;
};

Fraccao operator*(const Fraccao &a, const Fraccao &b);

Fraccao operator==(const Fraccao &a, const Fraccao &f);
//Fraccao operator+=(const Fraccao &a, const Fraccao &f);
ostream &operator<<(ostream &os, const Fraccao &f);

#endif /* Fraccao_hpp */
