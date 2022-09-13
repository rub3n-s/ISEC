//
//  main.c
//  ex8
//
//  Created by rsantos on 06/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int maior_subida(int *tab, int dim) {
    int dif = 0, maiorDif = 0, posicao = 0;
    
    for (int i = 0; i < dim; i++) {
        dif = *(tab+i) - *(tab+i-1);
        
        if (dif > maiorDif) {
            maiorDif = dif;
            posicao = i;
        }
    }
    

    printf("Maior diferença: %d\n", maiorDif);
    
    return posicao;
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 4, 8, 9};
    
    printf("Posição: %d\n", maior_subida(tab, 4));
    
    return 0;
}
