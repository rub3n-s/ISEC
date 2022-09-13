//
//  main.cpp
//  ex1
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>
#define N 5

using namespace std;

struct Tabela {
    int mat[N];
} tabela;

Tabela preencheTabela(int num) {
    Tabela t;
    for (int i = 0; i < N; i++)
        t.mat[i] = num;
    return t;
}

void mostraTabela(Tabela t) {
    for (int i = 0; i < N; i++)
        cout << t.mat[i] << " ";
}

int elementoEm(Tabela t, int pos) {
    if (pos < 0 || pos > N)
        cout << "pos invalida" << endl;
    else
        return t.mat[pos];
    
    return t.mat[0];
}

int &elementoEm_v2(Tabela &t, int pos) {
    if (pos < 0 || pos > N)
        cout << "pos invalida" << endl;
    else
        return t.mat[pos];
    
    return t.mat[0];
}

int main(int argc, const char * argv[]) {
    Tabela t;
    
    t = preencheTabela(5);
    
    mostraTabela(t);
    cout << endl;
    
    cout << elementoEm(t,5) << endl;
    cout << elementoEm(t,3) << endl;
    elementoEm_v2(t, 3) = 15;
    cout << elementoEm(t,3) << endl;
    
    return 0;
}
