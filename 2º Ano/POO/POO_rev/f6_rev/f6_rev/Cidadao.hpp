//
//  Cidadao.hpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Cidadao_hpp
#define Cidadao_hpp

#include <string>
#include <iostream>

using namespace std;

class Cidadao {
    string nome;
    int bi;
    
public:
    Cidadao(string n, int b) : nome(n), bi(b) {}
    ~Cidadao() { cout << "a destruir...\n"; };
    
    void setNome(string n) { nome = n; }
    string getNome() const { return nome; }
    virtual int getBi() const { return bi; }
    
    //string getAsString() const;
};

#endif /* Cidadao_hpp */
