//
//  main.c
//  ficha2ex13
//
//  Created by Rúben Mendes Santos on 28/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    float x1,x2;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
    
    x1 = a + (b / (c + ((d+e) / (f + ( g / h)))));
    
    x2 = (((a / b) - 1) / (c * (c / d + 1))) + a;
    
    printf("x1 = %.2f\n", x1);
    printf("x2 = %.2f\n", x2);
    
    return 0;
}
