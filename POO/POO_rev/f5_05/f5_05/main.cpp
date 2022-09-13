//
//  main.cpp
//  f5_05
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Pessoa.hpp"
#include "Clube.hpp"

int main(int argc, const char * argv[]) {
    /*Pessoa a("Pedro", 20), b("Ruben", 22);
    Clube c(50);
    c.setMembroDoClube(&a, 0); // Pessoa a passa a pertencer ser membro do clube
    c.setMembroDoClube(&b, 1); // Idem Pessoa b
     */
    
    
    /*----------------------------------
    vector<Pessoa> populacao;
    
    cout << "Vou acrescentar a Maria: " << endl;
    populacao.push_back(Pessoa("Maria", 10));
    
    cout << "Vou acrescentar o João: " << endl;
    populacao.push_back(Pessoa("João", 25));
    
    cout << "Vou acrescentar o Paulo: " << endl;
    populacao.push_back(Pessoa("Paulo", 19));
    
    Clube c(50);
    c.setMembroDoClube(&populacao[0]);
    c.setMembroDoClube(&populacao[1]);
    c.setMembroDoClube(&populacao[2]);
    
    cout << c;
    */
    
    Pessoa p0("João", 10), p1("Maria", 20), p2("Jose", 30);
    Clube filatelia(5);
    Clube pesca(2);
    Clube c(50);
    
    c.setMembroDoClube(&p0);
    c.setMembroDoClube(&p1);
    c.setMembroDoClube(&p2);
    
    filatelia.setMembroDoClube(&p0);
    filatelia.setMembroDoClube(&p1);
    
    pesca.setMembroDoClube(&p0);
    pesca.setMembroDoClube(&p2);
    
    cout << c;
    cout << filatelia;
    cout << pesca;
    
    return 0;
}
