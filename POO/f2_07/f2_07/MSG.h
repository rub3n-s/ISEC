//
//  MSG.h
//  f2_07
//
//  Created by rsantos on 22/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef MSG_h
#define MSG_h
#include <iostream>

using namespace std;

class MSG {
    int numero;
    char letra;
    static int proxNumero;
    
    
    
public:
    MSG(char c = 'x'); //construtor com variavel por omissão
    MSG (const MSG &z);
    
    string getAsString() const;
    ~MSG();
};

#endif /* MSG_h */
