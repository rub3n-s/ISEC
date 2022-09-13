//
//  Banco.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Banco_hpp
#define Banco_hpp
#include "Conta.hpp"
#include <vector>

class Banco {
    string nome;
    vector<Conta> contas;
    
public:
    Banco(string n);
    
    void addConta(Conta c);
    void eliminarConta(int bi);
    bool depositar(int bi, int valor);
    bool levantar(int bi, int valor);
    int somaSaldos();
    string getAsString() const;
};

#endif /* Banco_hpp */
