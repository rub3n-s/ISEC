//
//  main.cpp
//  f2_01
//
//  Created by rsantos on 21/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#define N 5

using namespace std;

struct Tabela {
    int num[N];
};

Tabela preenche(Tabela t, int n) {
    for (int i = 0; i < N; i++) {
        t.num[i] = n;
    }
    
    return t;
}

void listar(Tabela t) {
    for (int i = 0; i < N; i++) {
        cout << t.num[i];
    }
    cout << "\n";
}

int elementoEm(Tabela t, int pos) {
    if (pos >= 0 && pos < N)
        return t.num[pos];
    else
        return 0;
}

Tabela atualizaElemento(Tabela t, int pos, int n) {
    if (pos >= 0 && pos < N)
        t.num[pos] = n;
    
    return t;
}

int &elementoEm_v2(Tabela &t, int pos) {
    if (pos >= 0 && pos < N)
        return t.num[pos];
    else
        return t.num[0];
}

int main(int argc, const char * argv[]) {
    Tabela a;
    
    a = preenche(a, 5);
    listar(a);
    cout << elementoEm(a, 4) << endl;
    //a = atualizaElemento(a, 4, 2);
    
    elementoEm_v2(a, 4) = 15;
    listar(a);
    
    return 0;
}
