//
//  main.cpp
//  f3_06
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Pessoa.hpp"
#include "Clube.hpp"

int main(int argc, const char * argv[]) {
    Clube c("Clube 1", "Futebol");
    cout << c.getAsString() << endl;
    
    Pessoa p1("Antonio", 12312441, 1241412);
    Pessoa p2("Maria", 156465, 2124312);
    Pessoa p3("Jose", 1135325, 125232);
    Pessoa p4("Ana", 112314, 2427623);
    
    c.addPessoa(p1);
    c.addPessoa(p2);
    c.addPessoa(p3);
    c.addPessoa(p4);
    
    cout << c.getAsString() << endl;
    
    c.addPessoa(p1);
    
    return 0;
}
