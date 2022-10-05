//
//  main.c
//  ex2
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void trocarNum(float *primeira, float *segunda, float *terceira) {
    float temp = *segunda;
    
    *segunda = *primeira;
    *primeira = *terceira;
    *terceira = temp;
}

int main(int argc, const char * argv[]) {
    float a = 1.0, b = 2.5, c = 3.7;
//    float *x1 = &a, *y1 = &b, *z1 = &c;
    
//    printf("a = ");
//    scanf("%f", &a);
//
//    printf("b = ");
//    scanf("%f", &b);
//
//    printf("c = ");
//    scanf("%f", &c);
    
    trocarNum(&a, &b, &c);
    
    printf("%f\n", a);
    printf("%f\n", b);
    printf("%f\n", c);
              
    return 0;
}
