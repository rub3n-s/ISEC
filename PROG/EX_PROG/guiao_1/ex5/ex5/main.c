//
//  main.c
//  ex5
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 5;

#include <stdio.h>

int comuns(int *tabA, int tamA, int *tabB, int tamB) {
    int cont = 0;
    
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (tabA[i] == tabB[j]) {
                printf("tabA[%d] = tabB[%d] => %d\n", i, j, tabA[i]);
                cont++;
            }
        }
    }
    
    return cont;
}

int main(int argc, const char * argv[]) {
    int tabA[] = {1, 2, 3, 4, 5}, tabB[] = {0, 7, 3, 8, 5};
    printf("\nContador: %d\n", comuns(tabA, 5, tabB, 5));
    
    return 0;
}
