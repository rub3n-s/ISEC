//
//  Clube.hpp
//  f5_05
//
//  Created by rsantos on 24/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef Clube_hpp
#define Clube_hpp

#include <stdio.h>
#include <sstream>
#include "Pessoa.hpp"


class Clube {
    Pessoa **socios;
    unsigned int tam;
    unsigned int nSocios = 0;
    
public:
    Clube(unsigned int t);
    Clube(const Clube &r);
    ~Clube();
    
    Clube &operator=(const Clube &r);
    string getAsString() const;
    bool setMembroDoClube(Pessoa *p); //coloca na 1ª posicao livre (se houver lugar)
};
#endif /* Clube_hpp */
