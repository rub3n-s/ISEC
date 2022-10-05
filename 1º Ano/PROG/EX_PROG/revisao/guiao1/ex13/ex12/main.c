//
//  main.c
//  ex12
//
//  Created by rsantos on 06/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

double produto_escalar (double *a, double *b, int n) {
    int prod = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f x %.2f = %.2f\n",  *(a + i), *(b + i), *(a + i) * *(b + i));
            prod+= *(a + i) * *(b + i);
            i++;
        }
    }
    return prod;
}

int main(int argc, const char * argv[]) {
    double a[] = {1, 2, 3, 4}, b[] = {1, 2, 3, 4}, n = 4;
    
    printf("Produto = %.2f\n", produto_escalar(a, b, n));
    
    return 0;
}
