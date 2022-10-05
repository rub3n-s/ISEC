//
//  Poema.hpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Poema_hpp
#define Poema_hpp

#include <string>

using namespace std;

class Poema {
    string titulo;
    string * pVersos;
    int nVersos;
    
public:
    Poema(string t);
    Poema(const Poema &p);
    ~Poema();
    
    Poema &operator=(const Poema &p);
    
    void eliminaVerso(int pos);
    void acrescentaVerso(const string &verso);
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Poema &p);

#endif /* Poema_hpp */
