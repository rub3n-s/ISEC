//
//  main.cpp
//  f6_01
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <random>
#include "Peixe.hpp"
#include "Aquario.hpp"

double getRealUniform() {
    static default_random_engine e(time(0));
    static uniform_real_distribution<double> d(0.0, 1.0);
    
    return d(e);
}

int main(int argc, const char * argv[]) {
    Peixe *p1 = new Peixe("Nemo", "Laranja");
    Peixe *p2 = new Peixe("Dori", "Azul");
    cout << *p1;
    cout << *p2;
    
    Aquario *a = new Aquario;
    
}

