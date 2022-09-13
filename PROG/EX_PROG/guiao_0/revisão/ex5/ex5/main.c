//
//  main.c
//  ex5
//
//  Created by rsantos on 10/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 5

#include <stdio.h>

int verifica(int tab[], int tam, int num) {
    for (int i = 0; i < tam; i++) {
        if (tab[i] == num)
            return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int tab[TAM];
    
    for (int i = 0; i < TAM; i++) {
        if (i == 0) {
            printf("i[%d]: ", i);
            scanf("%d", &tab[i]);
        } else {
            do {
                printf("i[%d]: ",i);
                scanf("%d", &tab[i]);
                
                if (tab[i] < tab[i-1] || tab[i] == tab[i-1])
                    printf("Ordem Crescente Obrigatória!\n");
            } while(tab[i] < tab[i-1] || tab[i] == tab[i-1]);
        }
    }
    
    printf("%d\n", verifica(tab, TAM, 5));
    
    return 0;
}
