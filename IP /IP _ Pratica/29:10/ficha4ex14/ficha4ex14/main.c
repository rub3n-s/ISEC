//
//  main.c
//  ficha4ex14
//
//  Created by Rúben Mendes Santos on 29/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num_original = 1, prox_mult = 1, multiplicador = 0;
    
    while (1) {
        int alg_unidades = num_original % 10;
        int restantes_dig = num_original / 10;
        
        if (num_original == prox_mult) {
            multiplicador = prox_mult;
            prox_mult = prox_mult * 10;
        }
        
        int novo_num = alg_unidades * multiplicador + restantes_dig;
        
        if (novo_num == 4 * num_original) {
            printf("Num Original: %d | Novo Num: %d\n", num_original, novo_num);
            break;
        }
        
        num_original++;
    }
    
    return 0;
}
