//
//  MSG.hpp
//  f2_07
//
//  Created by rsantos on 01/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef MSG_hpp
#define MSG_hpp

#include <stdio.h>
#include <string>

using namespace std;

class MSG {
    char letra;
    int numero;
    static int proxNumero;
    
public:
    MSG(char c = 'x');
    MSG(const MSG &z);
    ~MSG();
    
    string getAsString() const;
};

#endif /* MSG_hpp */
