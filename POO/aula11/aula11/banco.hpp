//
//  banco.hpp
//  aula11
//
//  Created by rsantos on 10/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef banco_hpp
#define banco_hpp

#include <vector>
#include "conta.hpp"

using namespace std;

class Banco {
    string nome;
    vector<Conta> contas;
    
public:
    Banco(string no) : nome(no) {}
    string getAsString() const;
    bool addConta(Conta c);
};

#endif /* banco_hpp */
