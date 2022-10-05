//
//  main.cpp
//  f2_02
//
//  Created by rsantos on 21/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;

class Tabela {
    static int const N = 5;
    int mat[N];
    
public:
    Tabela(int num) {
        for (int i = 0; i < N; i++) {
            mat[i] = num;
        }
    }
    
    void printTab() const;
    int &elementoEm(int pos);
};

void Tabela::printTab() const {
    for (int i = 0; i < N; i++) {
        cout << mat[i];
    }
    cout << endl;
}

int &Tabela::elementoEm(int pos) {
    if (pos >= 0 && pos < N)
        return mat[pos];
    else
        return mat[0];
}

int main(int argc, const char * argv[]) {
    Tabela t(0);
    
    t.printTab();
    t.elementoEm(4) = 5;
    t.printTab();
    
    return 0;
}
