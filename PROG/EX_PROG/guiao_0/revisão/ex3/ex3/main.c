//
//  main.c
//  ex3
//
//  Created by rsantos on 09/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 5

#include <stdio.h>

int maisComum(int tab[], int tam) {
    int contador = 0, maior = tab[0], posicao = 0;
    
    for (int i = 0; i < TAM; i++) {
        if (tab[i] > maior)
            maior = tab[i];
    }
    
    printf("Maior numero: %d\n", maior);
    
    for (int i = 0; i < TAM; i++) {
        if (tab[i] == maior){
            posicao = i;
            contador++;
            printf("Posição: %d\n", posicao);
        }
    }
    
    return contador;
}

int main(int argc, const char * argv[]) {
    int tab[] = {2, 4, 3, 4, 2};
    
    printf("Nº de vezes %d\n", maisComum(tab, TAM));
    
    return 0;
}
