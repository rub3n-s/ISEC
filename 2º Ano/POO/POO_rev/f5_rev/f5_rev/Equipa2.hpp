//
//  Equipa2.hpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Equipa2_hpp
#define Equipa2_hpp

#include "Pessoa.hpp"

using namespace std;

class Equipa {
    Pessoa* jogadores[11];
    int pos;
    
public:
    Equipa();
    Equipa(const Equipa &e);
    ~Equipa();
    
    Equipa &operator=(const Equipa &e);
    
    void setJogador (Pessoa *p);
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Equipa &e);

#endif /* Equipa2_hpp */
