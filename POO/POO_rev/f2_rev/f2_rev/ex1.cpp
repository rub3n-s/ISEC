//
//  ex1.cpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ex1.hpp"

void Tabela::preenche(int num) {
    for (int i = 0; i < N; i++)
        tab[i] = num;
}

void Tabela::mostra() {
    for (int i = 0; i < N; i++)
        cout << tab[i] << " ";
    cout << "\n";
}

int Tabela::elementoEm(int pos) {
    if (pos < 0 || pos > N)
        return tab[0];
    else
        return tab[pos];
}

int Tabela::alteraElemento(int pos, int num) {
    if (pos < 0 || pos > N)
        return 0;
    else
        return tab[pos] = num;
}

int &Tabela::elementoEm_v2(int pos) {
   if (pos < 0 || pos > N)
        return tab[0];
    else
        return tab[pos];
}
