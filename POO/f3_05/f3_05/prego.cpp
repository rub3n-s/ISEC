//
//  prego.cpp
//  f3_05
//
//  Created by rsantos on 05/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "prego.hpp"
#include <iostream>

Prego::Prego(int a, int b) {
    x = a; y = b;
    cout << "construindo prego em " << x << "," << y << "\n";
}
    
Prego::~Prego() {
    cout << "destruindo prego em " << x << "," << y << "\n";
}
    
void Prego::mudaDeSitio(int a, int b) {
    x = a;
    y = b;
}

string Prego::getAsString() const {
    return "Prego em (" + to_string(this->x) + ", " + to_string(this->y) + ")\n";
}
