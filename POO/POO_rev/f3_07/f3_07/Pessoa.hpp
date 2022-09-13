//
//  Pessoa.hpp
//  f3_07
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
    int numBI;
    int numContribuinte;
    
public:
    Pessoa(string n, int bi, int cont);
    
    string getAsString() const;
    
    string getNome() const { return nome; }
    int getBI() const { return numBI; }
    int getContribuinte() const { return numContribuinte; }
    
    void setNome(string n) { nome = n; }
    void setBI(int bi) { numBI = bi; }
    void setContribuinte(int c) { numContribuinte = c; }
    
    void removeAluno(int bi);
};

#endif /* Pessoa_hpp */
