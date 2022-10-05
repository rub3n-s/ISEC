//
//  main.c
//  ex20f02
//
//  Created by Rúben Mendes Santos on 15/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int dia, mes, ano, num_anos, i;
    float montante, taxa;
    
    printf("Data atual: ");
    scanf("%2d/%2d/%4d", &dia, &mes, &ano);
    
    printf("Montante inicial: ");
    scanf("%f", &montante);
    
    printf("Taxa: ");
    scanf("%f", &taxa);
    
    printf("Numero de anos: ");
    scanf("%d", &num_anos);
    
    for (i = 0; i <= num_anos; i++){
        montante += (taxa/100)*montante;
        
        printf("No dia %d/%d/%d vai ter no banco %.2f euros\n", dia, mes, ano+i, montante);
    }
    
    return 0;
}
