//
//  main.cpp
//  f2_001
//
//  Created by rsantos on 18/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

//#include "tabela.hpp"
#include <iostream>

#define N 5

using namespace std;

class Tabela {
    int array[N];
    
public:
    void mostraTab(int a[]);
    void preencheTab(int num, int a[]);
};

void Tabela::mostraTab(int a[]) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << endl;
    }
    cout << endl;
}

void Tabela::preencheTab(int num, int a[]) {
    for (int i = 0; i < N; i++) {
        a[i] = N;
    }
}

int main(int argc, const char * argv[]) {
    Tabela t[N];
    
    preencheTab(5, t);
    mostraTab(t);
    
    return 0;
}
