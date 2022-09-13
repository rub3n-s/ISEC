//
//  main.c
//  ex3
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 6
#include <stdio.h>

void verificaVal(int tab[], int tam) {
    int soma = 0;
    
    for (int i = 0; i < TAM; i++) {
        printf("i[%d] = ", i);
        scanf("%d", &tab[i]);
        
        soma+=tab[i];
    }
    
    float media = soma/TAM;
    
    printf("\nMedia = %.2f\n\n", media);
    
    for (int i = 0; i < TAM; i++) {
        if(tab[i] < media)
            tab[i] = 0;
        
        printf("i[%d] = %d\n", i, tab[i]);
    }
    
}
int main(int argc, const char * argv[]) {
    int tab[TAM];
    
    verificaVal(tab, TAM);
    
    return 0;
}
