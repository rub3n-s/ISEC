//
//  main.c
//  ex18
//
//  Created by rsantos on 19/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void media_coluna(int n_lin, n_col, float mat[n_lin][n_col], int *min, int *max) {
    float media_colunas[n_col], val_max = 0, val_min = 0, soma = 0;
    
    int i, j;
    
    for (j = 0; j < n_col; j++) {
        *(media_colunas + j) = 0;
        //media_colunas[j] = 0, é igual a linha de cima
        
        for (i = 0; i < n_lin; i++)
            *(media_colunas + j) += *(mat[i] + j);
        
        media_colunas[j] = *(media_colunas + j) =* (media_colunas + j)/n_lin;
        
        printf("\n A média da coluna %d é %f", j, *(media_colunas + j));
    }
    
    val_max = *media_colunas; //valor max é inicializado ao primeiro elemento, entao o proximo ciclo nao precisa começar em zero
    //val_max = media_colunas[0];
    val_min = *media_colunas;
    
    for (j = 1; j < n_col; j++) {
        if (val_min >= *(media_colunas + j)) {
            val_min = *(media_colunas + j);
            *min = j;
        }
        
        if (*(media_colunas + j) > val_max) {
            val_max = *(media_colunas + j);
            *max = j;
        }
    }
}

int main(int argc, const char * argv[]) {
    float m1[3][2] = {
        {1.0, 4.5},
        {-2.5, 8.9},
        {0.3, 1.4}
    };
    float m2[2][6] = {
        {1.0, 1.6, 4.2, 1.4, 0.5, -3.4},
        {2.5, 8.1, 0.9, -0.1, 0.8, 3.5}
        
    };
    int min1=0, max1=0, min2=0, max2=0;

    // Chamar a função para a matriz m1: Preencher os indices min1 e max1
    printf("Matriz 1: \n");
    media_coluna(3, 2, m1, &min1, &max1);
    
    // Chamar a função para a matriz m2: Preencher os indices min2 e max2
    printf("\n\nMatriz 2: \n");
    media_coluna(2, 6, m2, &min2, &max2);
    
    printf("\n\nMatriz m1: (%d, %d)\n", min1, max1);
    printf("\nMatriz m2: (%d, %d)\n", min2, max2);
    return 0;
}
