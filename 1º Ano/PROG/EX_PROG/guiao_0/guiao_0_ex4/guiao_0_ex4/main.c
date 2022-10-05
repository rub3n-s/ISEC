//
//  main.c
//  ex1
//
//  Created by rsantos on 25/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int comum(int tab[], int tam) {
    int j = 0, contador[tam], maior = tab[0], maiorPos = contador[0];
    
    do {
        int soma = 0;
        //printf("j: tab[%d] = %d\n", j, tab[j]);
        
        for (int i = 0; i < tam; i++) {
            //printf("i: tab[%d] = %d\n", i, tab[i]);
            
            if (tab[j] == tab[i]) {
                soma++;
                contador[j] = soma;
            }
        }
        
        j++;
    } while(j < tam);
    
    for (int i = 0; i < tam; i++) {
        printf("contador[%d] = %d\n", i, contador[i]);
        
        if (maior < tab[i] && maiorPos <= contador[i]) {
            maior = tab[i];
            maiorPos = contador[i];
        }
    }
    
    printf("\nMais comum %d na posição %d\n", maior, maiorPos);
    return 0;
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 53, 2, 53, 63, 72, 63, 72};
    
    comum(tab, 8);
    
    return 0;
}
