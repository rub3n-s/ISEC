//
//  main.c
//  teste_experimental_2
//
//  Created by rsantos on 27/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

float Custo(int h, int m) {
    float custo = 0;
    
    if ((h = 0) && (m < 45))
        custo = 0;
    else if ((h >= 1) && (h < 3))
        custo = (h + m/60) * 0.4;
    else if (h > 3)
        custo = (h + m/60) * 0.8;
    
    return custo;
}

int main(int argc, const char * argv[]) {
    int horas, min, clientes;
    float custo_estacionamento;
    
    printf("Nº de Clientes: ");
    scanf("%d", &clientes);
    
    for (int i = 1; i <= clientes; i++) {
        do {
            printf("hh:mm\n");
            scanf("%d %d", &horas, &min);
        } while(horas < 0 || min < 0 || min >= 60);
        
        custo_estacionamento = Custo(horas,min);
        
        if (custo_estacionamento == 0)
            printf("Pode sair. Não precisa de pagar.\n");
        else
            printf("Valor a pagar = %f\n", custo_estacionamento);
    }
    
    return 0;
}
