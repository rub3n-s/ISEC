//
//  main.cpp
//  f2_01 (1)
//
//  Created by rsantos on 06/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

#define N 5

using std::cout;

struct Tabela {
    int mat[N];
};

Tabela preenche() {
    Tabela t;
    
    for (int i = 0; i < N; i++) {
        t.mat[i] = 5;
    }
    
    return t;
}

void mostra(Tabela t) {
    for (int i = 0; i < N; i++) {
        cout << t.mat[i] << " ";
    }
    cout << std::endl;
}

int elementoEm(Tabela t, int pos) {
    if (pos >= 0 && pos < N)
        return t.mat[pos];
    else
        return 0;
}

/*Tabela atualiza(Tabela t, int pos, int num) {
    if (pos >= 0 && pos < N)
        t.mat[pos] = num;
    else
        cout << "posição inválida!\n";
    
    return t;
} */

int &atualiza(Tabela &t, int pos) {
    if (pos >= 0 && pos < N)
        return t.mat[pos];
    else
        return t.mat[0];
}

int main(int argc, const char * argv[]) {
    Tabela a;
    
    a = preenche();
    mostra(a);
    cout << "Elemento na posição 3: " << elementoEm(a, 3) << std::endl;
    //a = atualiza(a, 3, 7);
    //mostra(a);
    //cout << "Elemento na posição 3: " << elementoEm(a, 3) << std::endl;
    
    atualiza(a, 3) = 15;
    mostra(a);
    cout << "Elemento na posição 3: " << elementoEm(a, 3) << std::endl;

    return 0;
}
