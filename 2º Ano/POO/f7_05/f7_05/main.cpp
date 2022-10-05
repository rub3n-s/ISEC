//
//  main.cpp
//  f7_05
//
//  Created by rsantos on 14/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Cartao.h"
#include "Tagarela.h"
#include "FalaPouco.hpp"
#include "Rede.hpp"

int main(int argc, const char * argv[]) {
    Rede r;
    cout << "rede sem cartoes: " << r << endl;
    
    r.addCartao(123, 10, indicetarifario::TAGARELA);
    r.addCartao(234, 25, indicetarifario::FALAPOUCO);
    r.addCartao(245, 15, indicetarifario::TAGARELA);
    
    cout << "rede com cartoes: "<< r << endl;
    
    r.delCartao(567);
    r.delCartao(234);
    cout << "rede depois de apagar cartoes 567 e 234\n" << r << endl;
    
    cout << "carregaCartao(123, 50) " << r.carregaCartao(123, 50) << endl;
    cout << "rede depois de carregar o cartao 123\n" << r << endl;
    
    Rede r2;
    r2.addCartao(111, 1, indicetarifario::FALAPOUCO);
    
    r2 = r;
    cout << "atribuicao: " << r2 << endl;
    
    /*Cartao c(123, 10);
    cout << "cartao sem tarifario: " << c << endl;
    
    Tarifario *t = new FalaPouco();
    c.adereTarifario(t);
    cout << "cartao com tarifario: " << c << endl;
    
    cout << "carregamento de 2: " << t->carrega(2) << endl;
    c.carrega(30);
    
    cout << "autoriza chamada: " << c.autorizaChamada() << endl;
     */
    
    return 0;
}
