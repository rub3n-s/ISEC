//
//  main.c
//  ficha4_ex3
//
//  Created by rsantos on 11/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

const float TAXA_A = 1.06;
const float TAXA_NA = 1.23;

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num_clientes, soma_pa, soma_pna;
    float preco, total_a_iva, total_na_iva, total_sem_iva;
    char tipo_prod;
    
    printf("Quantos clientes? ");
    scanf("%d", &num_clientes);
    
    soma_pa = 0; soma_pna = 0;
    total_a_iva = 0; total_na_iva = 0; total_sem_iva = 0;
    
    for(int i = 1; i <= num_clientes; i++) {
        printf("\nCliente %d: \n\n", i);
        
        do {
            printf("Preço, Tipo Produto ");
            scanf("%f, %c", &preco, &tipo_prod);
            
            if (preco > 0.0) {
                total_sem_iva += preco;
                
                if (tipo_prod == 'a' || tipo_prod == 'A') {
                    soma_pa += 1;
                    total_a_iva += preco * TAXA_A;
                }
                else if (tipo_prod == 'n' || tipo_prod == 'n') {
                    soma_pna += 1;
                    total_na_iva += preco * TAXA_NA;
                }
            }
        } while(preco > 0.0);
        
        printf("\n\nTalão do cliente %d\n", i);
        printf("Nº produtos alimentares: %d\n", soma_pa);
        printf("Nº produtos não alimentares: %d\n", soma_pna);
        printf("Nº total de produtos: %d\n", soma_pa + soma_pna);
        printf("Preço s/ IVA: %f\n", total_sem_iva);
        printf("Preço c/ IVA produtos alimentares: %f\n", total_a_iva);
        printf("Preço c/ IVA produtos não alimentares: %f\n", total_na_iva);
    }
    
    return 0;
}
