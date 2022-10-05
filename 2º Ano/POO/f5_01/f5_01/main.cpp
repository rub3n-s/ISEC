//
//  main.cpp
//  f5_01
//
//  Created by rsantos on 19/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "MSG.hpp"

void func(MSG* &a, MSG* &b) {
    a = new MSG("msgA");
    b = new MSG("msgB");
    
    cout << "objetos criados\n";
}

int main() {
    
    MSG *am = new MSG[3];
    delete[] am;
    
    /*MSG *a = nullptr, *b = nullptr;
    
    func(a, b);
    
    delete a;
    a = nullptr;
    
    delete b;
    b = nullptr;
    cout << "objetos libertados\n"; */
    
    
    /*
    int *ai = new int[10];
    int *bi = new int[10]();
    int *ci = new int[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    for(int i = 0; i < 10; i++) {
        ci[i] *= 2;
    }
    
    for(int *p = ci; p < ci+10; p++)
        cout << " " << *p;
    cout << "\n";
    
    delete[] ai;
    ai = nullptr;
    */
    
    return 0;
}
