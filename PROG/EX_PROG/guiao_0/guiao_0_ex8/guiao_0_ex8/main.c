//
//  main.c
//  guiao_0_ex8
//
//  Created by rsantos on 27/02/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define LINHAS 3

#include <stdio.h>

void matriz (int matriz[][3]) {
    int flag = 0;
    
    for (int i = 0; i < LINHAS; i++) {
        do {
            printf("mat[%d][0]: ", i);
            scanf("%d", &matriz[i][0]);
            flag = (matriz[i][0] < 1 || matriz[i][0] > 100);
            
            for (int j = 0; j < i && !flag;  j++) {
                if (matriz[j][0] == matriz[i][0])
                    flag = 1;
            }
            
            if(flag)
                printf("Valor Inválido\n");
        } while(flag);
        
        matriz[i][1] = matriz[i][0] * matriz[i][0];
        matriz[i][2] = matriz[i][1] * matriz[i][0];
    }
}

int main(int argc, const char * argv[]) {
    int mat[LINHAS][3];
    
    matriz(mat);
    
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < 3; j++) {
            printf("mat[%d][%d]: %d \t", i, j, mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
