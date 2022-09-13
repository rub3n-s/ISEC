//
//  main.c
//  ex1
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, total;
    int *p, *q, *r;
    
    p = &a;
    q = &b;
    r = &total;

    printf("a b = ");
    scanf("%d %d", &a, &b);
    
    total = *p + *q;
    r = &total;
    
    printf("a= %d \t b= %d \t total= %d\n", *p, *q, *r);

    return 0;
}
