//
//  main.c
//  ex5
//
//  Created by rsantos on 27/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int comuns(int *tabA, int tamA, int *tabB, int tamB) {
    int contador = 0;
    
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            printf("i[%d]= %d\t j[%d]=%d\n", i, *(tabA + i), j, *(tabB + j));
            
            if (*(tabA + i) == *(tabB + j)) {
                contador++;
                i++;
            }
        }
    }
    
    return contador;
}

int main(int argc, const char * argv[]) {
    int tA[] = {1, 5, 7, 9}, tB[] = {1, 3, 5, 7, 9};
    
    printf("%d\n", comuns(tA, 4, tB, 5));
    
    return 0;
}
