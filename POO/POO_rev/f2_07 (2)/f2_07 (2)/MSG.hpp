//
//  MSG.hpp
//  f2_07 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef MSG_hpp
#define MSG_hpp
#include <string>

using namespace std;

class MSG {
    char letra;
    int numero;
    static int proxNumero;
    
public:
    MSG(char c = 'x');
    MSG(const MSG &c);
    ~MSG();
    
    string getAsString() const;
};

#endif /* MSG_hpp */
