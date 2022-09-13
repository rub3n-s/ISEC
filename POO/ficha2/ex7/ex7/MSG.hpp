//
//  MSG.hpp
//  ex7
//
//  Created by rsantos on 29/10/2021.
//

#ifndef MSG_hpp
#define MSG_hpp

#include <iostream>
#include <sstream>

using namespace std;

class MSG {
    char letra;
    int numero;
    static int nObj;
    
public:
    MSG();
    MSG(char l);
    MSG(const MSG &z);
    ~MSG();
    
    string getAsString() const;
};

#endif /* MSG_hpp */
