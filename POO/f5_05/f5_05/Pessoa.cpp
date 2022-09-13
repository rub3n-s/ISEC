//
//  Pessoa.cpp
//  f5_05
//
//  Created by rsantos on 24/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "Pessoa.hpp"

ostream &operator<<(ostream &os, const Pessoa &p) {
    os << p.getNome() << " " << p.getIdade();
    return os;
}
