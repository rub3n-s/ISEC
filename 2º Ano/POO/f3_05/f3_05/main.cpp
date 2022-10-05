//
//  main.cpp
//  f3_05
//
//  Created by rsantos on 05/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "aviso.hpp"

int main(int argc, const char * argv[]) {
    Prego p(1,2);
    Aviso a("Aviso A", &p);
    Aviso b("Aviso B", &p);
    
    cout << a.getLocal();
    cout << b.getLocal();
    
    p.mudaDeSitio(50, 60);
    
    cout << "Depois de mudar: " << "\n";
    cout << a.getLocal();
    cout << b.getLocal();
    
    return 0;
}
