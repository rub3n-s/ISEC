//
//  main.cpp
//  f5_05
//
//  Created by rsantos on 24/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Pessoa.hpp"
#include "Clube.hpp"
#include <vector>

int main(int argc, const char * argv[]) {
    
    vector<Pessoa> populacao;
    
    cout << "Vou acrescentar a Maria:\n";
    populacao.push_back(Pessoa("Maria", 10));
    
    cout << "Vou acrescentar o Joao:\n";
    populacao.push_back(Pessoa("Joao", 20));
    
    cout << "Vou acrescentar o Pedro:\n";
    populacao.push_back(Pessoa("Pedro", 30));
    
    Clube c(50);
    c.setMembroDoClube(&populacao[0]);
    c.setMembroDoClube(&populacao[1]);
    c.setMembroDoClube(&populacao[2]);
    
    cout << "Vou acrescentar a Joana:\n";
    populacao.push_back(Pessoa("Joana", 40));
    
    cout << "Clube c: " << c.getAsString() << "\n";
    
    //Pessoa p0("João", 10), p1("Maria", 20), p2("Jose", 30);
    //Clube filatelia(5);
    //Clube pesca(2);
    
    /*
    c.setMembroDoClube(&p0);
    c.setMembroDoClube(&p1);
    c.setMembroDoClube(&p2);
    
    filatelia.setMembroDoClube(&p0);
    filatelia.setMembroDoClube(&p1);
    
    pesca.setMembroDoClube(&p0);
    pesca.setMembroDoClube(&p2);
    
    cout << "Filatelia: " << filatelia.getAsString() << "\n";
    cout << "Pesca: " << pesca.getAsString() << "\n";
    
    Clube c3 = pesca;
    cout << "c3: " << c3.getAsString() << "\n";
    
    Clube c4(filatelia);
    cout << "c4: " << c4.getAsString() << "\n";
    */
    return 0;
}
