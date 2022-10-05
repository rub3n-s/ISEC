//
//  Clube.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Clube_hpp
#define Clube_hpp
#include "Pessoa.hpp"
#include <vector>
#include <iostream>

class Clube {
    string nome;
    string atividade;
    vector<Pessoa> pessoas;
    
public:
    Clube(string n, string ativ);
    
    void addPessoa(Pessoa p);
    string getAsString() const;
};

#endif /* Clube_hpp */
