//
//  main.c
//  ex7
//
//  Created by rsantos on 27/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void procura_dupla(int *tab, int tam, int *prim, int *seg) {
    int primeiro = tab[0], segundo = tab[0];
    
    for (int i = 0; i < tam; i++) {
        if (*(tab + i) > primeiro)
            primeiro = *(tab + i);
    }
    
    for (int i = 0; i < tam; i++) {
        if (*(tab + i) > segundo && primeiro > *(tab + i)) {
            segundo = *(tab + i);
        }
    }
    
    *prim = primeiro;
    *seg = segundo;
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 7, 8, 9}, primeiro, segundo;
    
    procura_dupla(tab, 4, &primeiro, &segundo);
    
    printf("Primeiro = %d\n", primeiro);
    printf("Segundo = %d\n", segundo);
    
    return 0;
}
