//
//  main.c
//  ex2
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, c, *p, *q, *s;
    
    printf("a b c = ");
    scanf("%d %d %d", &a, &b, &c);
    
    int aux = b;
    
    b = a;
    a = c;
    c = aux;
    
    p = &a;
    q = &b;
    s = &c;
    
    printf("a = %d\t b = %d\t c = %d\n", *p, *q, *s);
    return 0;
}
