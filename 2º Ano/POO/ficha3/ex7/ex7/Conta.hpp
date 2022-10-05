//
//  Conta.hpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#ifndef Conta_hpp
#define Conta_hpp

#include "Pessoa.hpp"

class Conta {
    Pessoa titular;
    int saldo;
public:
    Conta(Pessoa tit, int s);
    Conta(Pessoa tit);
    string getTitular() const;
    void setNomeTitular(string nome);
    int getBI() const;
    int getSaldo() const;
    void aumentarSaldo(int s);
    void diminuirSaldo(int s);
};

#endif /* Conta_hpp */
