//
//  ginasio.cpp
//  f7_04
//
//  Created by rsantos on 07/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ginasio.hpp"
#include <sstream>

Ginasio::~Ginasio() {
    for (size_t i = 0; i < clientes.size(); i++)
        delete clientes[i];
}

bool Ginasio::avancaRelogio(int n) {
    if (n < 0)
        return false;
    relogio+=n;
    return true;
}

string Ginasio::getAsString() const {
    ostringstream os;
    os << "minuto " << relogio;
    
    if (clientes.size() > 0) {
        os << " pertencem ao ginasio\n";
        for( auto c : clientes)
            os << " " << *c << "\n";
    }
    
    return os.str();
}

ostream &operator<<(ostream &os, const Ginasio &g) {
    os << g.getAsString();
    return os;
}

bool Ginasio::addCliente(Cliente *c) {
    if (!c)
        return false;
    clientes.push_back(c);
    return true;
}

bool Ginasio::assinalaEntrada(int cc) {
    int indiceAtleta = -1;
    for (size_t i = 0; i < clientes.size() && indiceAtleta < 0; ++i)
        if (clientes[i]->getCC() == cc)
            indiceAtleta = i;
    if (indiceAtleta < 0 || clientes[indiceAtleta]->emTreino())
        return false;
    for (size_t i = 0; i < clientes.size(); ++i)
        if(clientes[i]->emTreino())
            clientes[i]->reageEntrada();
        else
            if (indiceAtleta == i)
                clientes[i]->iniciaTreino(relogio);
    return true;
}

bool Ginasio::assinalaSaida(int cc) {
    int indiceAtleta = -1;
    for (size_t i = 0; i < clientes.size() && indiceAtleta < 0; ++i)
        if (clientes[i]->getCC() == cc)
            indiceAtleta = i;
    if (indiceAtleta < 0 || !clientes[indiceAtleta]->emTreino())
        return false;
    for (size_t i = 0; i < clientes.size(); ++i)
        if(clientes[i]->emTreino() && indiceAtleta != i)
            clientes[i]->reageSaida();
        else
            if (indiceAtleta == i)
                clientes[i]->terminaTreino(relogio);
    return true;
}

int Ginasio::registaPagamento(int cc) {
    for(size_t i = 0; i < clientes.size(); i++)
        if(clientes[i]->getCC() == cc)
            return clientes[i]->paga();
    return -1;
}
