//
//  main.c
//  ficha5ex1
//
//  Created by rsantos on 05/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int contador = 0;

float Calcula(float num) {
    printf("Contador: %d\n", ++contador);
    return num * num;
}

int main(int argc, const char * argv[]) {
    
    float numero;
    
    do {
        printf("\nNumero: ");
        scanf("%f", &numero);
        
        float quadrado = Calcula(numero);
        
        printf("Quadrado: %.3f\n", quadrado);
        printf("Contador: %d\n", ++contador);
    } while(numero != 0);
    
    return 0;
}
