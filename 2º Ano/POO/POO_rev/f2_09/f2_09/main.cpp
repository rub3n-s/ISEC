//
//  main.cpp
//  f2_09
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Televisao.hpp"

int main(int argc, const char * argv[]) {
    TV tv1({"rtp1", "rtp2", "sic", "tvi", "natgeo", "foxcrime"});
    
    tv1.liga();
    cout << tv1.getAsString() << endl;
    
    //tv1.desliga();
    //cout << tv1.getAsString() << endl;
    
    tv1.aumentaSom(6);
    cout << tv1.getAsString() << endl;
    
    TV tv2({"a", "v", "e", "f"});
    cout << tv2.getAsString() << endl;
    
    tv2.aumentaSom(3);
    cout << tv2.getAsString() << endl;
    
    return 0;
}
