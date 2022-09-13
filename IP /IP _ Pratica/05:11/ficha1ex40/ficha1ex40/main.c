//
//  main.c
//  ficha1ex40
//
//  Created by rsantos on 05/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int F2(int n) {
    int res;
    
    if (n > 0) {
        res = 1;
        do {
            res = res * n;
            n = n - 1;
        } while(n > 1);
    } else
        res = 0;
    
    return res;
}

int main(int argc, const char * argv[]) {
    int i = 5;
    
    do {
        int x = F2(i);
        printf("%d %d\n", i, x);
        i = i - 1;
    } while(i >= -5);
    
    return 0;
}
