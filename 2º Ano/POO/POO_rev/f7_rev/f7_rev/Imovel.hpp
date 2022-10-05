//
//  Imovel.hpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Imovel_hpp
#define Imovel_hpp

#include <string>

using namespace std;

class Imovel {
    int preco, area, andar;
    string codigo;
    static int conta;
    
public:
    Imovel(int pr, int ar, int an, string tipo);
    
    string getCodigo() const { return codigo; }
    int getPreco() const { return preco; }
    int getAndar() const { return andar; }
    string getAsString() const;
    
    virtual ~Imovel() {}
};

ostream &operator<<(ostream &os, const Imovel &i);

#endif /* Imovel_hpp */
