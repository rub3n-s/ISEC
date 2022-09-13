//
//  main.c
//  ex14
//
//  Created by rsantos on 19/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#define L1 3
#define C1 2
#define L2 4
#define C2 3

void escreve(int n_lin, int n_col, int m[n_lin][n_col]){
    
    int *p;
    
    printf("Hipótese 1:\n");
    for (int i = 0; i < n_lin; i++) {
        printf("\n");
        for (int j = 0; j < n_col; j++) {
            printf("\t%d", m[i][j]);
        }
    }
    
    printf("Hipótese 2:\n");
    for (int i = 0; i < n_lin; i++) {
        printf("\n");
        p=m[i];
        
        for (int j = 0; j < n_col; j++) {
            printf("\t%d", *(m[i] + j));
        }
    }
    
    printf("Hipótese 3:\n");
    p = m[0];
    for (int i = 0; i < n_lin * n_col; i++, p++) {
        
        if (i % n_col == 0)
        printf("\n");
        p=m[i];
    }
}

int main(int argc, const char * argv[]) {
    int mat1[L1][C1]={{1,2},{3,4},{5,6}};
    int mat2[L2][C2]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    printf("\nMatriz mat1:\n");
    escreve(L1, C1, mat1);
    
    printf("\nMatriz mat2:\n");
    escreve(L2, C2, mat2);
    
    return 0;
}
