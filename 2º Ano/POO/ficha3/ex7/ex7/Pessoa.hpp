//
//  Pessoa.hpp
//  ex7
//
//  Created by rsantos on 19/11/2021.
//

#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <iostream>

using namespace std;

class Pessoa {
    int bi;
    string nome;
    
public:
    Pessoa(int id,string n);
    
    string getNome() const;
    void setNome(string n);
    int getBI() const;
};

#endif /* Pessoa_hpp */
