//
//  main.cpp
//  ex2
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>
#define N 5

using namespace std;

class Tabela {
    int mat[N];
    
public:
    Tabela() {
        for (int i = 0; i < N; i++) {
            mat[i] = 0;
        }
    }
    void preencheTabela(int n);
    void mostraTabela() const;
    int elementoEm(int pos) const;
    int &elementoEm_v2(int pos);
};

void Tabela::preencheTabela(int n) {
    for (int i = 0; i < N; i++) {
        mat[i] = n;
    }
}

void Tabela::mostraTabela() const {
    for (int i = 0; i < N; i++)
        cout << mat[i] << " ";
}

int Tabela::elementoEm(int pos) const {
    if (pos < 0 || pos > N)
        return mat[0];
    return mat[pos];
}

int &Tabela::elementoEm_v2(int pos) {
    if (pos < 0 || pos > N)
        return mat[0];
    return mat[pos];
}

int main(int argc, const char * argv[]) {
    Tabela t;
    
    t.mostraTabela();
    cout << endl;
    
    t.preencheTabela(5);
    t.mostraTabela();

    cout << "\n" << t.elementoEm(3) << endl;
    
    t.elementoEm_v2(3) = 15;
    
    cout << "\n" << t.elementoEm(3) << endl;
    
    return 0;
}
