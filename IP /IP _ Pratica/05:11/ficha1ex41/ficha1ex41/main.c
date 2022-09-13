//
//  main.c
//  ficha1ex41
//
//  Created by rsantos on 05/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

float CalculaIMC(float peso, float altura) {
    float imc = peso / (altura * altura);
    
    return imc;
}

int main(int argc, const char * argv[]) {
    
    float peso_pessoa, altura_pessoa;
    
    printf("Peso Altura\n");
    scanf("%f %f", &peso_pessoa, &altura_pessoa);
    
    float imc_pessoa = CalculaIMC(peso_pessoa, altura_pessoa);
    
    if (imc_pessoa <= 18.5) {
        printf("Abaixo do peso normal\n");
    } else if (imc_pessoa <= 25) {
        printf("Peso normal\n");
    } else if (imc_pessoa <= 30) {
        printf("Acima do peso normal\n");
    } else {
        printf("Obesidade\n");
    }
    
    return 0;
}
