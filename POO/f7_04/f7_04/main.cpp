//
//  main.cpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "apressado.hpp"
#include "cliente.hpp"
#include "ginasio.hpp"

int main(int argc, const char * argv[]) {
    Ginasio g;
    cout << "Ginasio G:" << g << endl;
     
    g.addCliente(new Cliente("Jose", 123123123, new Apressado()));
    g.addCliente(new Cliente("Maria", 231241241, new Apressado()));
    
    cout << "Ginasio G com atletas:" << g << endl;
    
    cout << "Jose a entrar\n";
    g.assinalaEntrada(123123123);
    
    cout << "Maria a entrar\n";
    g.assinalaEntrada(231241241);
    
    g.avancaRelogio(30);
    
    cout << "Jose a sair\n";
    g.assinalaEntrada(123123123);
    
    cout << "Jose a pagar:\n";
    cout << g.registaPagamento(123123123);
    
    /*
    Tarifario *t = new Apressado();
    Cliente c("Jose", 123123123, t);
    
    Cliente d(c);
    Cliente e("Maria", 2312, nullptr);
    
    cout << "antes de adicionar treinos:\n" << c << endl;
    
    
    
    c.iniciaTreino(0);
    c.iniciaTreino(10);
    c.terminaTreino(30);
    c.iniciaTreino(50);
    c.terminaTreino(100);
    
    cout << "depois de adicionar treinos:\n" << c << endl;
    
    e = c;
    
    cout << "valor a pagar: " << c.paga();
    cout << "\ndepois de pagar os treinos:\n" << c << endl;
    
    cout << "cliente d: \n" << d << endl;
    cout << "cliente e: \n" << e << endl;
    */
    
    /*t->acrescentaTreinos(10);
    t->acrescentaTreinos(-20);
    t->acrescentaTreinos(50); */
    
    return 0;
}
