//
//  Conta.hpp
//  f3_07
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Conta_hpp
#define Conta_hpp

#include "Pessoa.hpp"

class Conta {
    int saldo;
    Pessoa titular;
    
public:
    Conta(int s, Pessoa p);
    
    string getAsString() const;
};

#endif /* Conta_hpp */
