//
//  main.c
//  ficha2ex8
//
//  Created by Rúben Mendes Santos on 17/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    float euros;
    
    printf("Insira o valor em euros: ");
    scanf("%f", &euros);
    
    printf("Moedas de 1 cent.: %.0f\n", euros / 0.01);
    printf("Moedas de 2 cent.: %.0f\n", euros / 0.02);
    printf("Moedas de 5 cent.: %.0f\n", euros / 0.05);
    printf("Moedas de 20 cent.: %.0f\n", euros/ 0.2);
    printf("Moedas de 50 cent.: %.0f\n", euros / 0.5);
    
    return 0;
}
