//
//  main.cpp
//  f5_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "MSG2.hpp"
#include "Equipa2.hpp"
#include "Clube2.hpp"
#include "Poema.hpp"

void func(MSG* a, MSG* b) {
    a = new MSG("msgA");
    b = new MSG("msgB");
    
    cout << "objetos criados\n";
}

int main(int argc, const char * argv[]) {
    /*MSG *a = new MSG("a");
    MSG *b = new MSG("b");
    delete a;
    delete b; */
    
    /*
    MSG *a = nullptr, *b = nullptr;
    func(a,b);
    
    delete a;
    a = nullptr;
    
    delete b;
    b = nullptr;
    
    MSG *am = new MSG[3];
    delete [] am; */
    
    /*Pessoa a("Eusebio"), b("Pele"), c("Cristiano"), d("Messi");
    EquipaFutebol e;
    
    e.setJogador(&a, 0);
    e.setJogador(&b, 1);
    e.setJogador(&c, 2);
    e.setJogador(&d, 3);
    
    //cout << a;
    cout << e; */
    
    /*
    Pessoa a("Joao"), b("Maria"), c("Jose"), d("Manel");
    Clube filatelia(50);
    
    filatelia.setMembroDoClube(&a, 0);
    filatelia.setMembroDoClube(&b, 1);
    filatelia.setMembroDoClube(&c, 2);
    filatelia.setMembroDoClube(&d, 3);
    
    Clube pesca(filatelia);
    
    cout << "filatelia: \n" << filatelia << endl;
    cout << "pesca: \n" << pesca << endl; */
    
    /*
    Poema a("Lusiadas");
    Poema b("Alto da Barca");
    
    cout << a;
    cout << b;
    
    string texto1("O lorem ipsum é .....");
    string texto2("Ontem asdafsgasg");
    string texto3("hgoje asd asdé .....");
    a.acrescentaVerso(texto1);
    a.acrescentaVerso(texto2);
    a.acrescentaVerso(texto3);
    cout << a;
    a.eliminaVerso(1);
    cout << a;
    */
    
    
    //MSG *a = new MSG("a");
    //MSG *b = new MSG("b");
    
    //delete b;
    //b = nullptr;
    //delete a;
    //a = nullptr;
    
    /*MSG *a = nullptr, *b = nullptr;
    func(a,b);
    
    MSG *mat = new MSG[3];
    delete[]mat;
    mat = nullptr; */
    
    /*Equipa e;
    
    
    e.setJogador(&j1);
    e.setJogador(&j2);
    e.setJogador(&j3);
    
    cout << e; */
    
    Pessoa j1("Eusebio"), j2 ("Pele"), j3("Cristiano");
    Clube c(50);
    
    c.setMembroDoClube(&j1);
    c.setMembroDoClube(&j2);
    c.setMembroDoClube(&j3);
    
    cout << "clube c" << c;
    
    return 0;
}
