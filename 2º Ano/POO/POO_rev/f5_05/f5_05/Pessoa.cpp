//
//  Pessoa.cpp
//  f5_05
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Pessoa.hpp"

Pessoa::Pessoa(string n, int i) : nome(n), idade(i) {
    if (idade < 0)
        idade = 0;
    cout << "a construir " << nome << endl;
}

Pessoa::Pessoa(const Pessoa &p) : nome(p.nome), idade(p.idade) {
    cout << "a contruir por cópia " << nome << endl;
}

ostream &operator<<(ostream &os, const Pessoa &p) {
    os << "nome: " << p.getNome() << ", idade: " << p.getIdade() << endl;
    return os;
}
