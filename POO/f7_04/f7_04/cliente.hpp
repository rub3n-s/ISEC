//
//  cliente.hpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef cliente_hpp
#define cliente_hpp

#include <iostream>
#include <string>
#include "tarifario.hpp"

class Cliente {
    string nome;
    int cc;
    Tarifario *tarifario = nullptr;
    int inicio;
    bool aTreinar = false;
    
public:
    Cliente(string no, int ncc, Tarifario *t) : nome(no), cc(ncc), tarifario(t), inicio(-1) {}
    Cliente(const Cliente &c);
    Cliente &operator=(const Cliente &);
    
    virtual ~Cliente() { delete tarifario; }
    
    int getCC() const { return cc; }
    bool emTreino() const { return aTreinar; }
    virtual string getAsString() const;
    virtual bool iniciaTreino(int i);
    virtual bool terminaTreino(int f);
    virtual int paga();
    
    virtual void reageEntrada()// = 0;
    {
        cout << "cliente " << nome << " a reagir a entrada\n";
    }
    virtual void reageSaida()// = 0;
    {
        cout << "cliente " << nome << " a reagir a saida\n";
    }
};

ostream &operator<<(ostream &os, const Cliente &c);

#endif /* cliente_hpp */
