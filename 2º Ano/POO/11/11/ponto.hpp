//
//  ponto.hpp
//  11
//
//  Created by rsantos on 12/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef ponto_hpp
#define ponto_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "ParOrdenado.h"

using namespace std;

class Ponto {
    int x;
    int y;
    
public:
    explicit Ponto(int xx = 0, int yy = 0) : x(xx), y(yy) {}
    
    operator ParOrdernado() const { return ParOrdernado(x, y); }
    
    Ponto &operator++(); // incremento pré-fixo
    Ponto &operator+=(const Ponto &p);
    Ponto operator++(int); // incremento pós-fixo
    
    friend istream &operator>>(istream &is, Ponto &p);
    
    string getAsString() const;
    int getX() const { return x; }
    int getY() const { return y; }
};

Ponto operator+(const Ponto &a, const Ponto &b);
bool operator==(const Ponto &a, const Ponto &b);
bool operator!=(const Ponto &a, const Ponto &b);
ostream &operator<<(ostream &os, const Ponto &p);

#endif /* ponto_hpp */
