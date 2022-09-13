//
//  main.cpp
//  f3_07
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Pessoa.hpp"
#include "Conta.hpp"
#include "Banco.hpp"

int main(int argc, const char * argv[]) {
    /*Pessoa p1("Ruben", 123456778, 124151255);
    Conta c1(500, p1);
    
    cout << p1.getAsString() << endl;
    cout << c1.getAsString() << endl;*/
    
    Banco b("Caixa Agricola");
    
    Pessoa p1("Ruben", 1, 2);
    Pessoa p2("Joao", 3, 4);
    Pessoa p3("Manuel", 5, 6);
    
    Conta c1(500, p1);
    Conta c2(200, p2);
    Conta c3(1000, p3);
    
    b.addConta(c1);
    b.addConta(c2);
    b.addConta(c3);
    
    cout << b.getAsString() << endl;
    return 0;
}
