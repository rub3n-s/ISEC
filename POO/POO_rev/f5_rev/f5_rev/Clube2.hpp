//
//  Clube2.hpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Clube2_hpp
#define Clube2_hpp
#include "Pessoa.hpp"

using namespace std;

class Clube {
    Pessoa * * socios;
    int tam;
    int nSocios;
    
public:
    Clube(int t);
    Clube(const Clube &c);
    ~Clube();
    
    Clube &operator=(const Clube &c);
    
    void setMembroDoClube(Pessoa *p);
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Clube &c);

#endif /* Clube2_hpp */
