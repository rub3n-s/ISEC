//
//  main.c
//  ficha1ex4
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float f, c;
    
    printf("Fahrenheit = ");
    scanf("%f", &f);
    
    c = (f-32) * 5/9;
    
    printf("Celsius = %.3f\n", c);
    return 0;
}
