//
//  FalaPouco.hpp
//  f7_05
//
//  Created by rsantos on 14/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef FalaPouco_hpp
#define FalaPouco_hpp

#include "Tarifario.h"

class FalaPouco: public Tarifario {
    double custoPorMinuto;
    double probBonus;
    
public:
    FalaPouco(double cpm = 0.25, double pb = 0.2, double carrMin = 10, double limBon = 10);
    
    virtual bool autorizaChamada(double saldo) override;
    virtual double custoChamada(int duracao) override;
    virtual double carrega(double quantia) override;
    virtual FalaPouco *clone() const override { return new FalaPouco(*this); }
    virtual string getNome() const override { return "falaPouco"; }
    
    virtual string getAsString() const;
    
    virtual ~FalaPouco() {}
};

ostream &operator<<(ostream &os, const FalaPouco &t);

#endif /* FalaPouco_hpp */
