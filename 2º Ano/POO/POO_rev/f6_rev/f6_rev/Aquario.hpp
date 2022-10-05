//
//  Aquario.hpp
//  f6_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Aquario_hpp
#define Aquario_hpp
#include "Peixe.hpp"
#include <vector>

class Aquario {
    vector<Peixe *> peixes;
    
public:
    Aquario() = default;
    
    bool addPeixe(Peixe *p);
    void encontraPeixe(int numSerie);
    void selfClean();
    Peixe* eliminaPeixe(int numSerie);
    void alimentarPeixes(int g);
    
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Aquario &a);

#endif /* Aquario_hpp */
