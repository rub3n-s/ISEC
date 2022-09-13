//
//  Pessoa.hpp
//  f5_05
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <string>
#include <iostream>

using namespace std;

class Pessoa {
    string nome;
    int idade;
    
public:
    Pessoa(string n, int i);
    Pessoa(const Pessoa &p);
    ~Pessoa() { cout << "a destruir " << nome << endl; }
    
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
};

ostream &operator<<(ostream &os, const Pessoa &p);
#endif /* Pessoa_hpp */
