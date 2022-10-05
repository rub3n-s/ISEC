//
//  main.c
//  ficha1ex45
//
//  Created by rsantos on 05/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int Contador(int num) {
    
    int divisores = 0;
    
    for (int a = 1; a <= num; a++) {
        if (num % a == 0)
            divisores++;
    }
    
    return divisores;
}

int main(int argc, const char * argv[]) {
    
    int numero;
    
    do {
        printf("Número:");
        scanf("%d", &numero);
        
        int divs = Contador(numero);
        
        if (divs == 2 && numero > 0) {
            printf("Número é primo!\n");
        } else // remover este else caso queira apenas verificar numeros primos
            printf("%d\n", divs);
    } while (numero > 0);
    
    return 0;
}
