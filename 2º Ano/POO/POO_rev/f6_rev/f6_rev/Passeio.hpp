//
//  Passeio.hpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Passeio_hpp
#define Passeio_hpp
#include "Cidadao.hpp"
#include <vector>

class Passeio {
    Cidadao lider;
    string vila;
    string data;
    vector<Cidadao *> participantes;
    
public:
    Passeio(Cidadao &c, string v, string d);
    
    string getAsString() const;
    void setDestino(int v);
    bool associarParticipante(Cidadao *c);
    void desassociarParticipante(int bi);
};

ostream &operator<<(ostream &os, const Passeio &p);

#endif /* Passeio_hpp */
