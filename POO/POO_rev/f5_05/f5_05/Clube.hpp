//
//  Clube.hpp
//  f5_05
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Clube_hpp
#define Clube_hpp

#include "Pessoa.hpp"

class Clube {
    Pessoa **socios;
    unsigned int tam;
    unsigned int nSocios = 0;
    
public:
    Clube(unsigned int t);
    Clube(const Clube &c);
    ~Clube();
    
    Clube &operator=(const Clube &r);
    bool setMembroDoClube(Pessoa * p);
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Clube &c);

#endif /* Clube_hpp */
