//
//  main.c
//  guiao_0_ex1
//
//  Created by rsantos on 20/02/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int maiorNum(int tab[], int tam) {
    int pos = 0;
    int maior = 0;
    
    for (int i = 1; i <= tam; i++) {
        if (tab[i] >= maior) {
            maior = tab[i];
            pos = i;
        }
    }
    
    return pos;
}

int main(int argc, const char * argv[]) {
    
    int tamanho;
    
    printf("Tamanho: ");
    scanf("%d", &tamanho);
    
    int tabela[tamanho];
    
    for (int i = 1; i <= tamanho; i++) {
        printf("Posição %d: ", i);
        scanf("%d", &tabela[i]);
    }
    
    printf("\nO maior número aparece na posição: %d\n", maiorNum(tabela, tamanho));
    
    return 0;
}
