//
//  Pessoa.hpp
//  f5_05
//
//  Created by rsantos on 24/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Pessoa {
    string nome;
    int idade;
    
public:
    Pessoa(string n, int i): nome(n), idade(i) {
        if (idade < 0)
            idade = 0;
        cout << "A construir " << nome << "\n";
    }
    
    Pessoa(const Pessoa &p) : nome(p.nome), idade(p.idade) {
        cout << "A construir por copia " << nome << "\n";
    }
    
    ~Pessoa() {
        cout << "A destruir " << nome << "\n";
    }
    
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
    
};

ostream &operator<<(ostream &os, const Pessoa &p);

#endif /* Pessoa_hpp */
