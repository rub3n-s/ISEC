//
//  main.cpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "MSG.hpp"
#include "Equipa.hpp"
#include "Clube.hpp"

void func(MSG *a, MSG *b) {
    a = new MSG("msgA");
    b = new MSG("msgB");
    
    delete a;
    delete b;
}

int main(int argc, const char * argv[]) {
    /*MSG *a = new MSG("a");
    MSG *b = new MSG("b");
    
    delete a;
    delete b;
    
    MSG *a = nullptr, *b = nullptr;
    func(a,b);
    
    MSG *am = new MSG[3];
    delete [] am;*/
    
    /*Equipa e;
    Pessoa *p1 = new Pessoa("Ruben");
    Pessoa *p2 = new Pessoa("Joao");
    Pessoa *p3 = new Pessoa("Pedro");
    
    e.setJogador(p1);
    e.setJogador(p2);
    e.setJogador(p3);
    
    cout << e; */
    
    Clube c(50);
    Pessoa *p1 = new Pessoa("Ruben");
    Pessoa *p2 = new Pessoa("Joao");
    Pessoa *p3 = new Pessoa("Pedro");
    
    c.setMembroDoClube(p1);
    c.setMembroDoClube(p2);
    c.setMembroDoClube(p3);
    
    cout << c;
    
    return 0;
}
