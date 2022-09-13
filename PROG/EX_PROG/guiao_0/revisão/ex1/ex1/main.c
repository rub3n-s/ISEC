//
//  main.c
//  ex1
//
//  Created by rsantos on 02/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define LIN 2
#define COL 3

#include <stdio.h>

void encontraMaior(int tab[][COL], int lin, int col) {
    int maior = 0;
    int posI = 0, posJ = 0;
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if(tab[i][j] > maior) {
                maior = tab[i][j];
                posI = i;
                posJ = j;
            }
        }
    }
    
    printf("Maior: %d na posição [%d][%d]\n\n", maior, posI ,posJ);
}

void mostrarTab(int tab[][COL], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d \t", tab[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    int tab[LIN][COL];
    
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &tab[i][j]);
        }
        printf("\n");
    }
    
    encontraMaior(tab, LIN, COL);
    mostrarTab(tab, LIN, COL);
    
    return 0;
}
