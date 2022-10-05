//
//  main.c
//  ex2
//
//  Created by rsantos on 09/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 5

#include <stdio.h>

int maior(int tab[]) {
    int maior = tab[0], contador = 0, pos = 0; // maior = tab[0] porque se começar maior = 0 vai uma comparação haver um a mais na contagem
    
    for (int i = 0; i < TAM; i++) {
        if (tab[i] > maior) {
            maior = tab[i];
            pos = i;
            contador++;
            printf("maior: %d\n", maior);
        }
    }
    printf("Maior número: %d, Aparece na posição %d\n\n", maior, pos);
    
    return contador;
}
int main(int argc, const char * argv[]) {
    int tab[] = {3, 5, 6, 2, 6};
    
    printf("O maior número aparece %d vezes\n", maior(tab));
    
    return 0;
}
