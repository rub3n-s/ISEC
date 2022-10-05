//
//  Televisao.hpp
//  f2_09
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Televisao_hpp
#define Televisao_hpp

#include <vector>
#include <string>

using namespace std;

class TV {
    static const int MAX_CANAIS = 10; //alinea a) impõe maximo de 10 canais
    vector<string> canais;
    bool ligada = true;
    int som = 0;
    int canalAtual = 1;
    
public:
    TV(initializer_list<string> ca);
    
    string getAsString() const;
    bool liga();
    bool desliga();
    void aumentaSom(int v) { som+=v; }
    void diminuiSom(int v) { som-=v; }
};

#endif /* Televisao_hpp */
