//
//  main.c
//  ex6
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void vizinhos(int *tab, int dim, int *igual) {
    int media = 0;
    int contador = 0;
    
    for (int i = 0; i < dim; i++) {
        printf("i[%d]: %d\n", i, *(tab + i));
        
        if (i == 0) { //verifica os dois valores posteriores à ultima posição
            printf("%d \t %d\n", *(tab+1), *(tab+2));
            media = (*(tab+1) + *(tab+2)) / 2;
            printf("media = %d\n\n", media);
            printf("-------------------------\n");
        } else if(i == dim - 1){ //verifica os dois valores anteriores à ultima posição
            printf("%d \t %d\n", *(tab+i-1), *(tab+i-2));
            media = (*(tab+i-1) + *(tab+i-2)) / 2;
            printf("media = %d\n\n", media);
            printf("-------------------------\n");
        } else {
            printf("%d \t %d\n", *(tab+i-1), *(tab+i+1));
            media = (*(tab+i-1) + *(tab+i+1)) / 2;
            printf("media = %d\n\n", media);
            printf("-------------------------\n");
        }
        
        if (media == *(tab + i)) {
            contador++;
            printf("Media igual na posição i[%d]\t *(tab + i): %d", i, *(tab + i));
            printf("\n-------------------------\n\n");
        }
        
        media = 0;
    }
    
    printf("Contador = %d\n", contador);
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 2, 3, 4};
    int igual = 0;
    
    vizinhos(tab, 4, &igual);
    
    return 0;
}
