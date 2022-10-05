//
//  tarifario.hpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef tarifario_hpp
#define tarifario_hpp

#include <vector>
#include <string>

using namespace std;

class Tarifario {
    //vector<int> duracoes;
    int *duracoes = nullptr;
    size_t nTreinos;
    
protected:
    void apagaTreinos();
    
public:
    Tarifario() = default;
    Tarifario(const Tarifario &f);
    Tarifario &operator=(const Tarifario &t);
    
    int getNumTreinos() const { return nTreinos; }
    int getDuracoesTreinosI(size_t i);
    virtual Tarifario *clone() = 0;
    bool acrescentaTreinos(int dur);
    virtual int calculaPagamento() = 0;
    /* {   // corpo usado para testar as funções da classe
        apagaTreinos();
        return 0;
    } */
    virtual string getAsString() const;
    virtual ~Tarifario() { delete duracoes; }
};

ostream &operator<<(ostream &os, const Tarifario &t);

#endif /* tarifario_hpp */
