//
//  Clube.hpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Clube_hpp
#define Clube_hpp
#include "Pessoa.hpp"

class Clube {
    Pessoa * * socios;
    int tam;

public:

    Clube(int t);
    Clube (const Clube &c);
    ~Clube();
    
    Clube &operator=(const Clube &c);
    
    void setMembroDoClube(Pessoa * p, int pos) {
        socios[pos] = p;
    }
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Clube &c);

#endif /* Clube_hpp */
