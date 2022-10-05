//
//  ginasio.hpp
//  f7_04
//
//  Created by rsantos on 07/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ginasio_hpp
#define ginasio_hpp
#include <vector>
#include "cliente.hpp"

class Ginasio {
    int relogio = 0;
    vector<Cliente *> clientes;
    
public:
    Ginasio() = default;
    Ginasio(const Ginasio &) = delete;
    Ginasio &operator=(const Ginasio &) = delete;
    
    bool avancaRelogio(int n);
    bool addCliente(Cliente *c);
    virtual bool assinalaEntrada(int cc);
    bool assinalaSaida(int cc);
    virtual string getAsString() const;
    virtual int registaPagamento(int cc);
    virtual ~Ginasio();
};

ostream &operator<<(ostream &os, const Ginasio &g);

#endif /* ginasio_hpp */
