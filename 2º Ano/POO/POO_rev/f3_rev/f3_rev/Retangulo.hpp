//
//  Retangulo.hpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Retangulo_hpp
#define Retangulo_hpp
#include "Ponto.hpp"

class Retangulo {
    Ponto cse;
    int altura;
    int largura;
    
public:
    Retangulo(int larg, int alt, Ponto cantoSE);
    ~Retangulo();
    
    string getAsString() const;
    void setCSE(Ponto p) { cse = p; }
    int area() { return altura * largura; }
};

#endif /* Retangulo_hpp */
