//
//  tabela.hpp
//  f2_01 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef tabela_hpp
#define tabela_hpp

#define N 5

/*truct Tabela {
    int arr[N];
}; */

class Tabela {
    int arr[N];
    
public:    
    Tabela preencheTab(Tabela &t, int num);
    void mostraTab(Tabela t);
    int elementoEm(Tabela t, int pos);
    Tabela atualizaTab(Tabela &t, int pos, int valor);
    int &elementoEm_v2(Tabela &t, int pos);
};

#endif /* tabela_hpp */
