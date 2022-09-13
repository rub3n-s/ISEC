//
//  main.c
//  ex6
//
//  Created by rsantos on 27/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void vizinhos(int *tab, int dim, int *igual) {
    int contador = 0;
    
    for (int i = 0; i < dim; i++) {
        float media = 0;
        
        if (i == 0) {
            printf("i[%d] = %d\t%d\n", i, *(tab + 1), *(tab + 2));
            
            media = (*(tab + 1) + *(tab + 2))/2;
            
            if (media == *tab) {
                contador++;
                printf("Iguais\n\n");
            }
        } else if (i == dim - 1) {
            printf("\ni[%d] = %d\t%d\n", i,*(tab+i-1), *(tab+i-2));
            media = (*(tab + i - 1) + *(tab + i - 2))/2;
            
            if (media == *(tab + i)) {
                contador++;
                printf("Iguais\n\n");
            }
        }
        else {
            printf("\ni[%d] = %d\t%d\n", i,*(tab+i-1), *(tab+i+1));
            media = (*(tab + i - 1) + *(tab + i + 1))/2;
            
            if (media == *(tab + i)) {
                contador++;
                printf("Iguais\n\n");
            }
        }
    }
    
      *igual = contador;
}

int main(int argc, const char * argv[]) {
    int tab[] = {1, 1, 1, 1¬}, igual;
    
    vizinhos(tab, 4, &igual);
    
    printf("\nContador = %d\n", igual);
    
    return 0;
}
