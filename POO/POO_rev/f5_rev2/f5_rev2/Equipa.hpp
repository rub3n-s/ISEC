//
//  Equipa.hpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Equipa_hpp
#define Equipa_hpp

#include "Pessoa.hpp"

class Equipa {
    Pessoa * jogadores[11];
    int pos;
    
public:
    Equipa();
    Equipa(const Equipa &e);
    Equipa &operator=(const Equipa &e);
    
    bool setJogador(Pessoa * p);
    string getAsString() const;
    
    ~Equipa() { delete *jogadores; }
};

ostream &operator<<(ostream &os, const Equipa &e);

#endif /* Equipa_hpp */
