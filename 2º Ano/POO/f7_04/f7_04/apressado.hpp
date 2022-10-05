//
//  apressado.hpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef apressado_hpp
#define apressado_hpp

#include "tarifario.hpp"

class Apressado: public Tarifario {
public:
    virtual int calculaPagamento() override;
    virtual Apressado *clone() override { return new Apressado(*this); }
    virtual string getAsString() const override;
    virtual ~Apressado() = default;
};

ostream &operator<<(ostream &os, const Apressado &t);

#endif /* apressado_hpp */
