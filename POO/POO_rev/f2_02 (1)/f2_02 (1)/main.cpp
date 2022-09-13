//
//  main.cpp
//  f2_02 (1)
//
//  Created by rsantos on 06/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

#define N 5

using std::cout;

class Tabela {
    int mat[N];
    
public:
    Tabela(int num) {
        
    }
    
    Tabela preenche(int num);
    void mostra();
    int elementoEm(Tabela t, int pos);
    int &atualiza(Tabela &t, int pos);
};

Tabela Tabela::preenche(int num) {
    Tabela t(0);
    
    for(int i = 0; i < N; i++)
        mat[i] = num;
    
    return t;
}

void Tabela::mostra() {
    for (int i = 0; i < N; i++) {
        cout << mat[i] << " ";
    }
    cout << std::endl;
}

int Tabela::elementoEm(Tabela t, int pos) {
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

int &Tabela::atualiza(Tabela &t, int pos) {
    if (pos >= 0 && pos < N)
        return t.mat[pos];
    else
        return t.mat[0];
}

int main(int argc, const char * argv[]) {
    Tabela a(0);
    
    a.mostra();
    
    a.preenche(5);
    a.mostra();
    
    //cout << "Elemento na posição 3: " << elementoEm(a, 3) << std::endl;
    //a = atualiza(a, 3, 7);
    //mostra(a);
    //cout << "Elemento na posição 3: " << elementoEm(a, 3) << std::endl;
    
    //atualiza(a, 3) = 15;
    //mostra(a);
    //cout << "Elemento na posição 3: " << elementoEm(a, 3) << std::endl;

    return 0;
}
