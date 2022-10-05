//
//  Tarifario.hpp
//  f7_04_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Tarifario_hpp
#define Tarifario_hpp

#include <iostream>
#include <string>

using namespace std;

class Tarifario {
    int * duracoes = nullptr;
    size_t nTreinos;
    static int conta;
    
protected:
    void apagaTreinos();
    
public:
    Tarifario() = default;
    Tarifario(const Tarifario &t);
    Tarifario &operator=(const Tarifario &t);
    
    size_t getNumTreinos() const { return nTreinos; }
    int getDuracaoTreinoI(size_t i) const;
    bool acrescentaTreino(int duracao);
    virtual int calculaPagamento();
    
    string getAsString() const;
    
    virtual ~Tarifario() { delete duracoes; }
};

ostream &operator<<(ostream &os, const Tarifario &t);

#endif /* Tarifario_hpp */
