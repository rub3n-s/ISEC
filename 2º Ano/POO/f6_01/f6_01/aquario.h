//
//  aquario.h
//  f6_01
//
//  Created by rsantos on 10/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef aquario_h
#define aquario_h

#include <vector>
#include "peixe.h"

using namespace std;

class Aquario {
    vector<Peixe *> peixes;
    
public:
    Aquario() = default;
    Aquario(const Aquario &) = delete;
    
    Peixe *removePeixe(unsigned int n);
    bool addPeixe(Peixe *p);
    string getAsString() const;
    void alimentaPeixes(unsigned int c);
    void selfClean();
    bool peixeExiste(unsigned int n) const;
    
    Aquario &operator=(const Aquario &) = delete;
    ~Aquario();
};

ostream &operator<<(ostream &os, const Aquario &p);

#endif /* aquario_h */
