//
//  Apressado.hpp
//  f7_04_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Apressado_hpp
#define Apressado_hpp

#include "Tarifario.hpp"

class Apressado : public Tarifario {

public:
    int calculaPagamento() override;
    
    virtual string getAsString() const;
    virtual ~Apressado() = default;
};

ostream &operator<<(ostream &os, const Apressado &a);

#endif /* Apressado_hpp */
