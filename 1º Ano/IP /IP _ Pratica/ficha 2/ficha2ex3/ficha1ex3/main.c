//
//  main.c
//  ficha1ex3
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {

    int c1, c2;
    float h;
    
    printf("Cateto 1: ");
    scanf("%d", &c1);
    
    printf("Cateto 2: ");
    scanf("%d", &c2);
    
    h = sqrt(c1*c1 + c2*c2);
    
    printf("Hipotnusa = %f\n", h);
    
    return 0;
}
