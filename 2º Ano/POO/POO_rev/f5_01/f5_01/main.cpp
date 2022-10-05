//
//  main.cpp
//  f5_01
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "MSG.hpp"

void func(MSG* &a, MSG* &b) {
    a = new MSG("msgA");
    b = new MSG("msgB");
}

int main(int argc, const char * argv[]) {
    //MSG *a = nullptr, *b = nullptr;
    MSG *am = new MSG[3];
    delete[] am;
    
    //delete b; delete a;
    
    //func(a,b);
    
    return 0;
}
