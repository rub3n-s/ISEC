//
//  ex1.hpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ex1_hpp
#define ex1_hpp

#include <iostream>
#define N 5

using namespace std;

class Tabela {
    int tab[N];
    
public:
    Tabela(int num = 0) {
        for (int i = 0; i < N; i++)
            tab[i] = num;
    }
    void preenche(int num);
    void mostra();
    int elementoEm(int pos);
    int alteraElemento(int pos, int num);
    int &elementoEm_v2(int pos);
};

#endif /* ex1_hpp */
