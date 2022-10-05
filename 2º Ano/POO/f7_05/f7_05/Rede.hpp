//
//  Rede.hpp
//  f7_05
//
//  Created by rsantos on 14/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Rede_hpp
#define Rede_hpp

#include <vector>
#include "Cartao.h"
#include "Tarifario.h"

using namespace std;

enum indicetarifario {
    TAGARELA = 0,
    FALAPOUCO = 1
};

class Rede {
    vector<Cartao *> cartoes;
    vector<Tarifario *> tarifarios;
    
public:
    Rede();
    Rede(const Rede &r) = delete;
    Rede &operator=(const Rede &r);
    
    string listarCartoes() const;
    string listarTarifarios() const;
    string getAsString() const;
    
    bool addCartao(int numero, int saldo, indicetarifario i);
    bool delCartao(int numero);
    bool carregaCartao(int numero, double quantia) const;
    
    virtual ~Rede();
};

ostream &operator<<(ostream &os, const Rede &r);

#endif /* Rede_hpp */
