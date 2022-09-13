//
//  ex7.hpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ex7_hpp
#define ex7_hpp
#include <string>

using namespace std;

static int contador = 0;

class MSG {
    char letra;
    int num;
    
public:
    MSG(char l = 'x');
    MSG(const MSG &c);
    
    string getAsString() const;
};

#endif /* ex7_hpp */
