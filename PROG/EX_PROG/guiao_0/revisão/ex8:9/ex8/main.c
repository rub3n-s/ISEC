//
//  main.c
//  ex8
//
//  Created by rsantos on 10/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define COL 3

#include <stdio.h>

void mostrarMat(int tab[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
}
void quadCubo(int tab[][3], int linhas) {
    int flag = 0;
    
    for (int i = 0; i < linhas; i++) {
        do {
            printf("[%d][0]: ", i);
            scanf("%d", &tab[i][0]);
            flag = (tab[i][0] > 100 || tab[i][0] < 1);
            
            for (int j = 0; j < i  && !flag; j++) {
                if (tab[i][0] == tab[j][0])
                    flag = 1;
            }
            
            if (flag)
                printf("Valor inválido!\n");
        } while(flag);
        
        tab[i][1] = tab[i][0] * tab[i][0];
        tab[i][2] = tab[i][0] * tab[i][1];
    }
}

int main(int argc, const char * argv[]) {
    int linhas;
    
    printf("Linhas: ");
    scanf("%d", &linhas);
    
    int tab[linhas][COL];
    
    quadCubo(tab, linhas);
    printf("\n");
    
    mostrarMat(tab, linhas);
    
    
    return 0;
}
