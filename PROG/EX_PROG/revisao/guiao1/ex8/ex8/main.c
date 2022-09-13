//
//  main.c
//  ex8
//
//  Created by rsantos on 27/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#define N 4

int maior_subida(int *tab, int dim) {
    int dif[N], maior = *(dif), pos = 0;
    
    for (int i = 0; i < dim; i++) {
        if (i == 0) {
            printf("pos[%d]: %d\n", i, *(tab + i));
            *(dif + i) = *(tab + i);
        }
        else {
            printf("pos[%d]: %d\t - pos[%d]: %d\n", i, *(tab + i), i - 1, *(tab + i - 1));
            *(dif + i) = *(tab + i) - *(tab + i - 1);
            printf("diferença = %d\n\n", *(dif + i));
        }
    }
    
    for (int j = 0; j < dim; j++) {
        printf("%d\n", *(dif + j));
        if (maior < *(dif + j)) {
            maior = *(dif + j);
            pos = j;
        }
    }
    
    return pos;
}

int main(int argc, const char * argv[]) {
    int tab[] = {2, 6, 9, 12};
    
    printf("Posição = %d\n", maior_subida(tab, N));
    
    return 0;
}
