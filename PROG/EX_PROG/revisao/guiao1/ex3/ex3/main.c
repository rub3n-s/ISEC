//
//  main.c
//  ex3
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void verificaMedia(int tab[], int tam) {
    int soma = 0;
    
    for (int i = 0; i < tam; i++) {
        soma += *(tab + i);
        printf("tab[%d] = %d\n", i, *(tab + i));
    }
    printf("\n");
    
    float media = soma/tam;
    
    for (int i = 0; i < tam; i++) {
        if (media > tab[i])
            *(tab + i) = 0;
        
        printf("tab[%d] = %d\n", i, *(tab + i));
    }
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 6, 2, 25, 7};
    
    verificaMedia(tab, 5);
    
    return 0;
}
