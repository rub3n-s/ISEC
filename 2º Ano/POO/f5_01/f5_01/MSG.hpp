//
//  MSG.hpp
//  f5_01
//
//  Created by rsantos on 19/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef MSG_hpp
#define MSG_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class MSG {
public:
    MSG(const char *p = "") {
        cout << "ola" << p << "\n";
    }
    
    ~MSG() {
        cout << "Adeus\n";
    }
};

#endif /* MSG_hpp */
