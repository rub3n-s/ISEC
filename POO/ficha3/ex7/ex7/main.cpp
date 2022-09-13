//
//  main.cpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#include <iostream>
#include "Banco.hpp"

int main(int argc, const char * argv[]) {
    Banco b("CGD");
    Pessoa p1(123,"Manel");
    Pessoa p2(456,"José");
    Pessoa p3(789,"Tó");
    Pessoa p4(145,"Ze");
    
    Conta c1(p1, 1000);
    Conta c2(p2, 850);
    Conta c3(p3, 5030);
    Conta c4(p4);
    
    b.recebeConta(c1);
    b.recebeConta(c2);
    b.recebeConta(c3);
    b.recebeConta(c4);
    
    cout << b.getAsString() << endl;
    
    b.eliminaConta(123);
    cout << b.getAsString() << endl;
    cout << b.obterSoma() << "\n" << endl;
    
    Banco b2("BPI");
    Conta c5(p4);
    b2.recebeConta(c5);
    
    c5.setNomeTitular("mudou");
    
    cout << "-------------------------------------" << endl;
    cout << b.getAsString();
    cout << "-------------------------------------" << endl;
    cout << b2.getAsString() << endl;
    return 0;
}
