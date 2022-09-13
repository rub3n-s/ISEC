//
//  main.c
//  ficha4_ex2
//
//  Created by rsantos on 10/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i = 1;
    float soma = 0, salario;
    
//    printf("Numero de empregrados: ");
//    scanf("%d", &num_empregados);
//
//    do {
//        printf("Salário do empregado %d: ", i);
//        scanf("%f", &salario);
//
//        soma += salario;
//
//        i++;
//    } while (i <= num_empregados);
    
    do {
        printf("Salário do empregado %d: ", i);
        scanf("%f", &salario);

        if (salario > 0) {
            soma += salario;
            i++;
        }
        else
            i--;
    } while(salario > 0);
    
    printf("\nSalário medio: %f\n", soma/i);
    
    return 0;
}
