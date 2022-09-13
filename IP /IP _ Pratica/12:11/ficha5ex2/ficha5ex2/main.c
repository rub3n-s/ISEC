//
//  main.c
//  ficha5ex2
//
//  Created by rsantos on 12/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int VerificaLimites (int num, int limite1, int limite2) {
    int resultado = 0;
    
    /*------------------------------------------------------*/
//    int limite_inf, limite_sup;
    
//    if(limite1 < limite2){
//        limite_inf = limite1;
//        limite_sup = limite2;
//    } else {
//        limite_inf = limite2;
//        limite_sup = limite1;
//    }
    /*------------------------------------------------------*/
    if(num > limite1 && num < limite2) {
        resultado = 1;
    }
    

    
    return resultado;
}
int main(int argc, const char * argv[]) {
    int numero, lim1, lim2;
    int verifica = 0;

    //Opção para nao utilizar as variaveis limite_inf ou limite_sup;
    /*------------------------------------------------------*/
    do {
        printf("Num Lim1 Lim2\n");
        scanf("%d %d %d", &numero, &lim1, &lim2);
    } while(lim1 > lim2);
    /*------------------------------------------------------*/
    
    verifica = VerificaLimites(numero, lim1, lim2);
    
    if (verifica == 1)
        printf("Está dentro dos limites!\n");
    else
        printf("Está fora dos limites!\n");
    
    return 0;
}
