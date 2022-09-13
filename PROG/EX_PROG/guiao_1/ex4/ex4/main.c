//
//  main.c
//  ex4
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void verifica(int *tab, int tam, int *np, int *ni, int *maior, int *pos) {
    *maior = 0;
    
    for (int i = 0; i < tam; i++) {
        if(tab[i] % 2 == 0) //*(tab + i)
            (*np)++;
        else
            (*ni)++;
        
        if(tab[i] > *maior) {
            *maior = tab[i];
            *pos = i;
        }
    }
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 3, 7, 5, 2, 10, 9, 7, 7, 1};
    int npares = 0, nimpares = 0, nmaior, npos;
    
    verifica(tab, 10, &npares, &nimpares, &nmaior, &npos);
    
    printf("Pares: %d\n", npares);
    printf("Impares: %d\n", nimpares);
    printf("Maior: %d\n", nmaior);
    printf("Posição do maior: %d\n", npos);
    
    return 0;
}
