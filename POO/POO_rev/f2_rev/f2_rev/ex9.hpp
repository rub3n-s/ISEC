//
//  ex9.hpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ex9_hpp
#define ex9_hpp

#include <vector>
#include <string>

#define N 4

using namespace std;

class Televisao {
    vector<string> canais;
    string canal;
    bool ligada = false;
    int som = 0;
    
public:
    Televisao(vector<string> c);
    
    string getAsString() const;
    
    void ligaTV();
    void desligaTV();
    void aumentaSom();
    void diminuiSom();
    void ligaCanal(int c);
};

#endif /* ex9_hpp */
