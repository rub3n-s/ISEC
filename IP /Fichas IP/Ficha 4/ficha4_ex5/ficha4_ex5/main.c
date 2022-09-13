//
//  main.c
//  ficha4_ex5
//
//  Created by rsantos on 11/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int lim_inf, lim_sup;
    
    do {
        printf("limite inferior, limite superior: ");
        scanf("%d, %d", &lim_inf, &lim_sup);
    } while (lim_inf > lim_sup && (lim_inf < 0 || lim_sup < 0));
    
    for (int i = lim_inf; i <= lim_sup; i++) {
        if(i % 5 == 0 && i % 3 != 0)
            printf("%d\n", i);
    }
    
    return 0;
}
