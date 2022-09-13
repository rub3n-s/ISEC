//
//  Pessoa.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
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
    
    string getAsString() const;
    
    void setNome(string n) { nome = n; }
    
    string getNome() const { return nome; }
    int getBI() const { return bi; }
    int getContribuinte() const { return contribuinte; }
};

#endif /* Pessoa_hpp */
