//
//  Rede.cpp
//  f7_05
//
//  Created by rsantos on 14/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Rede.hpp"
#include "Tagarela.h"
#include "FalaPouco.hpp"
#include <sstream>

Rede::Rede() {
    tarifarios.push_back(new Tagarela());
    tarifarios.push_back(new FalaPouco());
}

Rede &Rede::operator=(const Rede &r) {
    if (this == &r)
        return *this;
    
    for(auto c : cartoes)
        delete c;
    cartoes.clear();
    
    for(auto t : tarifarios)
        delete t;
    tarifarios.clear();
    
    for (auto c : r.tarifarios)
        tarifarios.push_back(c->clone());
    
    for (auto c : r.cartoes) {
        Cartao *novo = c->clone();
        for (auto t : tarifarios) {
            if (t->getNome() == c->getNomeTarifario())
                novo->adereTarifario(t);
        }
        cartoes.push_back(novo);
    }
    return *this;
}

Rede::~Rede() {
    for (auto c : cartoes)
        delete c;
    for (auto t : tarifarios)
        delete t;
}

string Rede::listarCartoes() const {
    ostringstream os;
    
    for(auto c : cartoes)
        os << *c << " ";
    
    return os.str();
}

string Rede::listarTarifarios() const {
    ostringstream os;
    for(auto c : tarifarios)
        os << *c << "\n";
    return os.str();
}

string Rede::getAsString() const {
    ostringstream os;
    if (!tarifarios.empty())
        os << "Tarifarios:\n" << listarTarifarios();
    if (!cartoes.empty())
        os << "Cartoes:\n" << listarCartoes();
    return os.str();
}

ostream &operator<<(ostream &os, const Rede &r) {
    os << r.getAsString();
    return os;
}

bool Rede::addCartao(int numero, int saldo, indicetarifario i) {
    if (i < 0 || i >= tarifarios.size())
        return false;
    cartoes.push_back(new Cartao(numero, saldo, tarifarios[i]));
    return true;
}

bool Rede::delCartao(int numero) {
    auto it = cartoes.begin();
    while(it < cartoes.end()) {
        if ( (*it)->getNumero() == numero) {
            delete *it;
            cartoes.erase(it);
            return true;
        }
    ++it;
    }
    return false;
}

bool Rede::carregaCartao(int numero, double quantia) const {
    for(size_t i = 0; i < cartoes.size(); ++i)
        if (cartoes[i]->getNumero() == numero)
            return cartoes[i]->carrega(quantia);
    return false;
}
