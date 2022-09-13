//
//  main.cpp
//  f2_07 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "MSG.hpp"

int main(int argc, const char * argv[]) {
    MSG a('a');
    cout << a.getAsString() << endl;
    
    MSG b;
    MSG c(b);
    
    return 0;
}
