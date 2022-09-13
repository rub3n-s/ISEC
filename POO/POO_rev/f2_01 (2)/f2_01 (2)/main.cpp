//
//  main.cpp
//  f2_01 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "tabela.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Tabela t;
    
    t.preencheTab(t, N);
    t.mostraTab(t);
    cout << t.elementoEm(t, 3) << endl;
    t.atualizaTab(t, 3, 7);
    t.mostraTab(t);
    
    t.elementoEm_v2(t,4) = 15;
    cout << t.elementoEm_v2(t,4) << endl;
    
    return 0;
}
