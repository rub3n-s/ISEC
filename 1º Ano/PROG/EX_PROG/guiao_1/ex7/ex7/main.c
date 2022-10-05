//
//  main.c
//  ex7
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void procura_dupla(int *tab, int tam, int *prim, int *seg) {
    *prim = 0; *seg = 0;
    
    for (int i = 0; i < tam; i++) {
        if (*(tab + i) > *prim) {
            *prim = *(tab + i);
        }
    }
    
    for (int i = 0; i < tam; i++) {
        if (*(tab + i) < *prim && *(tab + i) > *seg) {
            *seg = *(tab + i);
        }
    }
    
    printf("1º = %d\n", *prim);
    printf("2º = %d\n", *seg);
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 2, 7, 4, 5, 6};
    int primeiro, segundo;
    
    procura_dupla(tab, 6, &primeiro, &segundo);
    
    return 0;
}
