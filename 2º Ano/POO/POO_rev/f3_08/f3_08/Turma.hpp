//
//  Turma.hpp
//  f3_08
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Turma_hpp
#define Turma_hpp

#include <vector>
#include "Pessoa.hpp"

class Turma {
    Pessoa professor;
    vector<Pessoa> alunos;
    string turma;
    
public:
    Turma(string t, const Pessoa &prof);
    
    string getAsString() const;
    void removeAluno(int bi);
    void addAluno(Pessoa p);
};

#endif /* Turma_hpp */
