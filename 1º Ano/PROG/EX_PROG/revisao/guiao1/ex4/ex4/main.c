//
//  main.c
//  ex4
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
void f(int *t, int tam, int *np, int *ni, int *maior, int *pos) {
    *maior = t[0],    *np = 0,    *ni = 0;
    
    for (int i = 0; i < tam; i++) {
        if (*(t + i) > *maior)
            *maior = *(t + i);
        
        if (*(t + i) % 2 == 0)
            (*np)++;
        else
            (*ni)++;
    }
    
    printf("Pares: %d\tImpares: %d\tMaior: %d\n", *np, *ni, *maior);
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 3, 7, 5, 2, 10, 9, 7, 7, 1}, npares, nimpares, nmaior, posicao;
    
    f(tab, 10, &npares, &nimpares, &nmaior, &posicao);
    
    printf("Pares: %d\tImpares: %d\tMaior: %d\n", npares, nimpares, nmaior);
    return 0;
}
