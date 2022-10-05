//
//  imovel.hpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef imovel_hpp
#define imovel_hpp

#include <string>

using namespace std;

class Imovel {
    static int conta;
    int area, andar, preco;
    string codigo;
    
public:
    Imovel(int pr, int ar, int an, string tipo) : area(ar), andar(an), codigo(tipo+to_string(conta++)), preco(pr) {}
    
    string getCodigo() const { return codigo; }
    int getConta() const { return conta; }
    string getAsString() const;
    
    virtual ~Imovel() {}
};

ostream &operator<<(ostream &os, const Imovel &i);

#endif /* imovel_hpp */
