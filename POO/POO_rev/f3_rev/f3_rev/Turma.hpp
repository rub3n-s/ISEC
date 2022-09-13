//
//  Turma.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Turma_hpp
#define Turma_hpp
#include <vector>
#include "Pessoa.hpp"

#define MAX 20
static int contador = 0;

class Turma {
    vector<Pessoa> alunos;
    Pessoa professor;
    
public:
    Turma(const Pessoa p);
    
    bool addAluno(Pessoa a);
    string getAsString() const;
    void removeAluno(int bi);
};

#endif /* Turma_hpp */
