//
//  Conta.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
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
    
    bool aumentaSaldo(int valor);
    bool diminuiSaldo(int valor);
    
    int getSaldo() { return saldo; }
    int getBI() const { return titular.getBI(); }
    
    string getAsString() const;
};

#endif /* Conta_hpp */
