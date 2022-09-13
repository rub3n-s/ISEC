//
//  Pessoa.hpp
//  f3_06
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <string>

using namespace std;

class Pessoa {
    string nome;
    int bi;
    int contribuinte;
    
public:
    Pessoa(string n, int b, int c);
    
    string getNome() const { return nome; }
    int getBI() const { return bi; }
    int getContribuinte() const { return contribuinte; }
    
    void setNome(string n) { nome = n; }
    void setBI(int b) { bi = b; }
    void setContribuinte(int c) { contribuinte = c; }
    
    string getAsString() const;    
};

#endif /* Pessoa_hpp */
