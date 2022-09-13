//
//  main.cpp
//  f2_03 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "caderno.hpp"

int main(int argc, const char * argv[]) {
    Caderno c("Oxford", "Verde", 250, 80, 50);
    
    cout << c.getAsString() << endl;
    
    return 0;
}
