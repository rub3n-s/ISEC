//
//  main.c
//  teste_experimental_4
//
//  Created by rsantos on 27/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

float CustoM(int d, float t, int e, float cmh, float cmkm) {
    return d*cmkm + t*cmh*e;
}

int main(int argc, const char * argv[]) {
    int dist, equipa, num_servicos;
    float tempo, customh, customkm, custo_total, menor_custo = 9999999;
    
    printf("Nº de Serviços: ");
    scanf("%d", &num_servicos);
    
    if(num_servicos > 6)
        printf("Maximo de 6 trajetos!");
    else {
        for (int i = 1; i <= num_servicos; i++) {
            printf("Cliente %d\n", i);
            printf("Distância Tempo Equipa Custo/Hora Custo/Km\n");
            scanf("%d %f %d %f %f", &dist, &tempo, &equipa, &customh, &customkm);
            
            custo_total = CustoM(dist,tempo,equipa, customh, customkm);
            
            if (custo_total < menor_custo)
                menor_custo = custo_total;
            
            printf("Custo do Serviço = %.2f\n\n", custo_total);
        }
        printf("Menor Custo = %.2f\n\n", menor_custo);
    }
    return 0;
}
