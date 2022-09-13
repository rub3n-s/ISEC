//
//  main.cpp
//  ex3
//
//  Created by rsantos on 03/11/2021.
//

#include <iostream>
#include "Retangulo.hpp"

int main(int argc, const char * argv[]) {
    Ponto cse(1,2);
    Retangulo r(cse, 4, 2);
    cout << r.getAsString() << endl;
    return 0;
}
