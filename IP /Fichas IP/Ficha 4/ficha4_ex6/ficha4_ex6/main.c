//
//  main.c
//  ficha4_ex6
//
//  Created by rsantos on 11/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int num, quantos_num;
    
    printf("Quantos numeros: ");
    scanf("%d", &quantos_num);
    
    for (int i = 1; i <= quantos_num; i++) {
        
        printf("\n%d: \n\n", i);
        
        do {
            printf("Numero: ");
            scanf("%d", &num);
        } while(num < 0);

        
        for (int j = 1; j <= num; j++) {
            if (num % j == 0)
                printf("%d\n", j);
        }
    }

    return 0;
}
