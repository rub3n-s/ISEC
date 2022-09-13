//
//  tabela.cpp
//  f2_01 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "tabela.hpp"
#include <iostream>

using namespace std;

Tabela Tabela::preencheTab(Tabela &t, int num) {
    for (int i = 0; i < N; i++) {
        t.arr[i] = num;
    }
    return t;
}

void Tabela::mostraTab(Tabela t) {
    for (int i = 0; i < N; i++)
        cout << t.arr[i] << " ";
    cout << "\n";
}

int Tabela::elementoEm(Tabela t, int pos) {
    if (pos < 0 || pos > N)
        return 0;
    return t.arr[pos];
}

Tabela Tabela::atualizaTab(Tabela &t, int pos, int valor) {
    t.arr[pos] = valor;
    return t;
}

int &Tabela::elementoEm_v2(Tabela &t, int pos) {
    if (pos < 0 || pos > N)
        return t.arr[0];
    return t.arr[pos];
}
