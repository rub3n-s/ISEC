//
//  FalaPouco.cpp
//  f7_05
//
//  Created by rsantos on 14/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "FalaPouco.hpp"
#include <ctime>
#include <random>
#include <sstream>

FalaPouco::FalaPouco(double cpm, double pb, double carrMin, double limBon) : Tarifario(carrMin, limBon), custoPorMinuto(cpm), probBonus(pb) {
    if (custoPorMinuto < 0)
        custoPorMinuto = 0;
    if (probBonus < 0)
        probBonus = 0;
}

bool FalaPouco::autorizaChamada(double saldo) {
    return saldo > -10 * custoPorMinuto;
}

double FalaPouco::custoChamada(int duracao) {
    if (duracao < 0)
        return 0.0;
    int minutos = duracao / 60;
    if (duracao % 60 > 0)
        ++minutos;
    return minutos * custoPorMinuto;
}

double getRealUniform01() {
    static default_random_engine e(static_cast<unsigned int>(time(0)));
    static uniform_real_distribution<double> d(0.0, 1.0);
    
    return d(e);
}

double FalaPouco::carrega(double quantia) {
    if (quantia < getCarregaMin())
        return 0;
    if (quantia < getLimiarBonus() && getRealUniform01() < probBonus)
        return 2*quantia;
    return quantia;
}

string FalaPouco::getAsString() const {
    ostringstream os;
    os << Tarifario::getAsString();
    os << " custo por minuto " << custoPorMinuto;
    os << " probabilidade de duplicar carregmento " << probBonus;
    return os.str();
}

ostream &operator<<(ostream &os, const FalaPouco &t) {
    os << t.getAsString();
    return os;
}
