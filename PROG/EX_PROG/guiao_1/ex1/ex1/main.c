//
//  main.c
//  ex1
//
//  Created by rsantos on 05/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, total, *p = &a, *q = &b, *r = &total;

    printf("a = ");
    scanf("%d", p);//como é um ponteiro não é necessario colocar o &(endereço) no scanf
    
    printf("\nb = ");
    scanf("%d", q);
    
    *r = *p + *q;
    
    printf("\na= %d \t b= %d \t total= %d\n", a, b, total);
    //ou
    printf("\na= %d \t b= %d \t total= %d\n", *p, *q, *r);

    return 0;
}
