//
//  Banco.hpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#ifndef Banco_hpp
#define Banco_hpp

#include <vector>
#include <iostream>
#include <sstream>
#include "Conta.hpp"

class Banco {
    string nome;
    vector<Conta> contas;
    
public:
    Banco(string n);
    
    void recebeConta(Conta c);
    void encontraConta(int bi);
    void eliminaConta(int bi);
    void depositar(int bi, int valor);
    int obterSoma() const;
    string getAsString() const;
};

#endif /* Banco_hpp */
