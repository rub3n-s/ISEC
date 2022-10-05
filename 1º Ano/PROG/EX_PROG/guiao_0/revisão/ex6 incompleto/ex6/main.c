//
//  main.c
//  ex6
//
//  Created by rsantos on 10/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 6

#include <stdio.h>

void calculaSoma(int tab[], int dim, int valor) {
    int soma = 0;
    
    for (int i = 0; i < TAM; i++) {
        soma+=tab[i];
        
        if (soma == 8) {
            printf("%d ", tab[i]);
        }        
    }
}

int main(int argc, const char * argv[]) {
    int tab[] = {1,-2, 3, 4, -5, 6};
    
    calculaSoma(tab, TAM, 8);
    
    return 0;
}
