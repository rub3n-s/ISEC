//
//  main.c
//  ficha4ex10
//
//  Created by Rúben Mendes Santos on 29/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

//incluir biblioteca para inserir o menor float possivel
#include <float.h>

int main(int argc, const char * argv[]) {
    float num, soma=0.0, contador=0;
    int continua = 1;
    float num_anterior = -FLT_MAX;
    
    do {
        scanf("%f", &num);
        
        if (num > num_anterior) {
            soma += num;
            contador++;
            num_anterior = num;
        } else {
            continua = 0;
        }
    } while(continua);
    
    printf("\nmédia = %.2f\n", soma / contador);
    printf("soma = %.2f\n", soma);
    return 0;
}
