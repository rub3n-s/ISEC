//
//  ParOrdenado.h
//  11
//
//  Created by rsantos on 17/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef ParOrdenado_h
#define ParOrdenado_h

#include <sstream>

using namespace std;

class ParOrdenado {
    int a, b;
    
    
public:
    ParOrdenado(int aa, int bb) : a(aa), b(bb) {}
    
    int getA() { return a; }
    int getB() { return b; }
};

ostream &operator<<(ostream &os, const ParOrdenado &p);

#endif /* ParOrdenado_h */
