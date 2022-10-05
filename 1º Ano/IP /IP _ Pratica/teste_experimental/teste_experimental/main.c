//
//  main.c
//  teste_experimental
//
//  Created by rsantos on 26/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

float Velocidade(int k, float t) {
    return k/t;
}

int main(int argc, const char * argv[]) {
    int num_func = 0, num_traj = 0, km = 0;
    float tempo = 0, media = 0, kmh = 0, soma = 0;
    
    printf("Nº de Funcionários\n");
    scanf("%d", &num_func);
    
    for (int i = 1; i <= num_func; i++) {
        
        printf("Funcionário %d\n\n", i);
        
        printf("Nº de Trajetos: \n");
        scanf("%d", &num_traj);
        
        for (int j = 1; j <= num_traj; j++) {
            
            tempo = 0;
            km = 0;
            
            printf("KM TEMPO\n");
            scanf("%d %f", &km, &tempo);
            
            kmh = Velocidade(km,tempo);
            
            if (kmh < 30)
                printf("Abaixo do limite permitido: %.2f\n\n", kmh);
            else if (kmh > 100)
                printf("Acima do limite permitido: %.2f\n\n", kmh);
            else
                printf("Velocidade no trajeto: %.2f\n\n", kmh);
            
            soma += kmh;
        }
        media = soma / num_traj;
        printf("Média Km por Trajeto: %.2f\n\n", media);
    }
    
    return 0;
}
