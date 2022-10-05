//
//  main.c
//  ex11
//
//  Created by rsantos on 04/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#define L1 2
#define C1 2
#define L2 2
#define C2 2

int verifica(int t1[][C1], int n1, int t2[][C2], int n2) {
    int contador = 0;
    
    if (L1 == L2 && C1 == C2) {
        for (int i = 0; i < L1; i++) {
            for (int j = 0; j < C1; j++) {
                if (t1[i][j] == t2[i][j]) {
                    contador++;
                } else
                    printf("t1[%d][%d]: %d != t2[%d][%d]: %d\n", i, j, t1[i][j], i, j, t2[i][j]);
            }
        }
        
        if (contador == L1 * L2)
            return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int tab1[L1][C1]={{1,3},{3,4}};
    int tab2[L2][C2]={{1,3},{3,4}};
    
    printf("%d\n", verifica(tab1, L1, tab2, L2));
    
    return 0;
}
