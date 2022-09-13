//
//  Clube.hpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Clube_hpp
#define Clube_hpp

#include <sstream>
#include "Pessoa.hpp"

class Clube {
    Pessoa * * socios;
    int tam;
    int nSocios;
    
public:

    Clube(int t);
    Clube(const Clube &c);
    Clube &operator=(const Clube &c);
    
    ~Clube();
    
    bool setMembroDoClube(Pessoa * p);
    
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Clube &c);

#endif /* Clube_hpp */
