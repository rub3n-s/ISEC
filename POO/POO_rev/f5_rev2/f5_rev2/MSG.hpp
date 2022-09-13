//
//  MSG.hpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef MSG_hpp
#define MSG_hpp
#include <iostream>

using namespace std;

class MSG {

public:

    MSG(const char * p = "x") {
        cout << "ola" << p << "\n";
    }
    ~MSG() {
        cout << "Adeus\n";
    }

};

#endif /* MSG_hpp */
