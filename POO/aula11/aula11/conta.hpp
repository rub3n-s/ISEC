//
//  conta.hpp
//  aula11
//
//  Created by rsantos on 10/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef conta_hpp
#define conta_hpp

#include <stdio.h>
#include "pessoa.hpp"

class Conta {
    Pessoa &titular;
    int saldo = 0;
public:
    Conta(Pessoa &pessoa) : titular(pessoa) {}
    bool levanta(int quantia);
    bool deposita(int quantia);
    const Pessoa &getPessoa() const { return titular; }
    string getAsString const;
};
#endif /* conta_hpp */
