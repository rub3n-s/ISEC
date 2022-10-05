//
//  main.c
//  ex4
//
//  Created by rsantos on 10/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 5

#include <stdio.h>

void maisComum(int tab[], int tam) {
    int maior = tab[0], contador = 0;
    
    for (int i = 0; i < tam; i++) {
        if (tab[i] > maior)
            maior = tab[i];
    }
    
    for (int i = 0; i < tam; i++) {
        if (tab[i] == maior)
            contador++;
    }
    
    printf("Maior: %d\n", maior);
    printf("Contador: %d\n", contador);
}

int main(int argc, const char * argv[]) {
    int tab[TAM];
    
    for (int i = 0; i < TAM; i++) {
        printf("i[%d]:  ", i);
        scanf("%d", &tab[i]);
    }
    
    maisComum(tab, TAM);
    
    return 0;
}
