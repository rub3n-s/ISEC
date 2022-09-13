//
//  Retangulo.hpp
//  f3_01
//
//  Created by rsantos on 20/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Retangulo_hpp
#define Retangulo_hpp

#include "Ponto.hpp"

class Retangulo {
    double altura, largura;
    Ponto cse;
    
public:
    Retangulo(const Ponto &p, double alt, double larg);
    ~Retangulo();
    
    string getAsString() const;
    void setCanto(const Ponto &p);
    double area() { return largura * altura; };
};

#endif /* Retangulo_hpp */
