//
//  retangulo.hpp
//  f3_01
//
//  Created by rsantos on 29/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef retangulo_hpp
#define retangulo_hpp

#include <stdio.h>
#include "ponto.h"

class Retangulo {
    Ponto cse; //canto superior esquerdo
    double altura, largura;
    
public:
    Retangulo(const Ponto &p, double alt, double lar);
    Retangulo(const Retangulo &r);
    ~Retangulo();
    
    string getAsString() const;
    
    double area() const;
    
    void setCanto(const Ponto &p);
};

#endif /* retangulo_hpp */
