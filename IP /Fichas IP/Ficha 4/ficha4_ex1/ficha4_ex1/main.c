//
//  main.c
//  ficha4_ex1
//
//  Created by rsantos on 10/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int numero;
    
    printf("Número:");
    scanf("%d", &numero);
    
    for (int i = 1; i <= 25; i++) {
        if (numero % i == 0)
            printf("%d\n", i);
    }
    
    return 0;
}
