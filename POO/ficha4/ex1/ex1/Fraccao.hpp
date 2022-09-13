//
//  Fraccao.hpp
//  ex1
//
//  Created by rsantos on 17/11/2021.
//

#ifndef Fraccao_hpp
#define Fraccao_hpp

#include <iostream>
#include <sstream>

using namespace std;

class Fraccao {
    int numerador;
    int denominador;
    
public:
    Fraccao();
    Fraccao(int n, int d);
    Fraccao operator+(const Fraccao& f);
    Fraccao operator*(const Fraccao& f);
    string getAsString() const;
    
    void setNumerador(int n);
    void setDenominador(int d);
    int getNumerador() const;
    int getDenominador() const;
};

#endif /* Fraccao_hpp */
