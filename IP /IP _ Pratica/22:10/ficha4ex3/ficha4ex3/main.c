//
//  main.c
//  ficha4ex3
//
//  Created by Rúben Mendes Santos on 22/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#define TAXA_A 1.06
#define TAXA_N 1.23

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float total_com_iva = 0.0, total_sem_iva = 0.0, preco;
    int num_a = 0, num_n = 0, num_total;
    char tipo;
    
    do {
        printf("preco, tipo: \n");
        scanf("%f, %c", &preco, &tipo);
        
        if (preco > 0.0) {
            if (tipo == 'a' || tipo == 'A') {
                total_com_iva += preco * TAXA_A;
                num_a++;
            }
            
            if (tipo == 'n' || tipo == 'N') {
                total_com_iva += preco * TAXA_N;
                num_n++;
            }
            
            total_sem_iva += preco;
        }
    } while (preco > 0.0);
    
    num_total = num_a + num_n;
    printf("Numero de produtos alimentares: %d \n", num_a);
    printf("Numero de produtos não alimentares: %d \n", num_n);
    printf("Numero de total de produtos: %d \n", num_total);
    printf("Preço total sem IVA: %.2f \n", total_sem_iva);
    printf("Preço total com IVA: %.2f \n", total_com_iva);
    return 0;
}
