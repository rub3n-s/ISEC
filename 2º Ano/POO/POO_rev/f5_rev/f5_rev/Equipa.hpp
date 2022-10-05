//
//  Equipa.hpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Equipa_hpp
#define Equipa_hpp

#include "Pessoa.hpp"

class EquipaFutebol {
    Pessoa * jogadores[11]; //máximo 11 jogadores
    
public:
    EquipaFutebol();
    EquipaFutebol(const EquipaFutebol &e);
    ~EquipaFutebol();
    
    void setJogador(Pessoa *p, int pos);
    string getAsString() const;
};

ostream &operator<<(ostream &os, const EquipaFutebol &e);
#endif /* Equipa_hpp */
