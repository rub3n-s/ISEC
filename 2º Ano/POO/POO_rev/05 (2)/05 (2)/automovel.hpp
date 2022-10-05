//
//  automovel.hpp
//  05 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef automovel_hpp
#define automovel_hpp

#include <string>

using namespace std;

/*struct Automovel {
    string matricula;
    string marca;
    string modelo;
    int combustivel;
};

Automovel preenche(string mat, string m, string mo, int co);
void mostra(Automovel a); */

class Automovel {
    string matricula;
    string marca;
    string modelo;
    int combustivel;
    
public:
    Automovel(string mat, string m, string mo, int co);
    
    string getAsString() const;
};

#endif /* automovel_hpp */
