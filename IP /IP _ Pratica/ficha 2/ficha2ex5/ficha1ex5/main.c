//
//  main.c
//  ficha1ex5
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int A, B, C;
    
    printf("A = ");
    scanf("%d", &A);
    
    printf("B = ");
    scanf("%d", &B);
    
    C = A;
    
    A = B;
    
    B = C;
    
    printf("\nA = %d e B = %d\n", A, B);
    
    return 0;
}
