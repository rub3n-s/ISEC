//
//  main.c
//  ficha1ex35
//
//  Created by Rúben Mendes Santos on 22/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, c, d, e, f, i, j, y;
    
    int resultado = 0;
    
    if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0 || f < 0){
        printf("números introduzidos não são todos positivos!\n");
        return -1; // sai do programa
    }
    
    printf("a, b, c, d, e, f ?\n");
    scanf("%d, %d, %d, %d, %d, %d", &a, &b, &c, &d, &e, &f);
    
    for (i = a; i <= b; i++) {
        for (j = c; j <= d; j++) {
            for(y = e; y <= f; y++) {
                resultado += i*j*y;
                
                printf("%d x %d x %d = %d \n", i, j, y, i*j*y);
            }
        }
    }
    
    printf("Resultado: %d\n", resultado);
    
    return 0;
}
