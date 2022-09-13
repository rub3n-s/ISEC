//
//  Banco.hpp
//  f3_07
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Banco_hpp
#define Banco_hpp

#include "Conta.hpp"
#include "Pessoa.hpp"
#include <vector>

class Banco {
    string nome;
    vector<Conta> contas;
    
public:
    Banco(string n);
    
    void addConta(Conta c);
    string getAsString() const;
    void getConta(int b);
};

#endif /* Banco_hpp */
