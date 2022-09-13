//
//  Triangulo.hpp
//  ex2
//
//  Created by rsantos on 03/11/2021.
//

#ifndef Triangulo_hpp
#define Triangulo_hpp

#include <iostream>
#include "Ponto.hpp"

class Triangulo {
    static int identificador;
    Ponto x;
    Ponto y;
    Ponto z;
    
public:
    Triangulo(Ponto a, Ponto b, Ponto c);
    ~Triangulo();
    
    string getPonto(Ponto p);
    string getAsString() const;
};
#endif /* Triangulo_hpp */
