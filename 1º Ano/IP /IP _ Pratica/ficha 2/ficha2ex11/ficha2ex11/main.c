//
//  main.c
//  ficha2ex11
//
//  Created by Rúben Mendes Santos on 17/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
// (a)
//    int x;
//
//    x = 3 + 4 * 5 - 6; printf("%d\n",x); // 17
//
//    x = 3 * 4 % 5 - 6; printf("%d\n",x); // -4
//
//    x = (7 + 6) % 5 / 2; printf("%d\n",x); // 1
    
// (b)
//    int x = 2, y, z;
//    x *= 3 + 2;
//    printf("%d\n", x); // 10
//
//    x *= y = 4;
//    printf("%d\t%d\n", x, y); // 40 4
//
//    z = (x == y);
//    printf("%d\t%d\t%d\n", x, y, z); // x=40 y=4 z=0
    
// (c)
//    int x, y = 1, z;
//    x = 0;
//    z = 1;
//    x = (x && y) || z;
//
//    printf("%d\n", x); // 1
//    printf("%d\n", x || (!y && z));  // 1
//    printf("%d\n", z >= y && y >= x); // 1 && 1 = 1
    
// (d)
//    int x, y, z;
//    x = y = z = -1;
//    ++x || ++y || ++z;
//
//    printf("%d %d %d\n", x, y, z);
//
//    x = y = z = -1;
//    ++x && ++y && ++z;
//
//    printf("%d %d %d\n", x, y, z);
//
 
// (e)
    int i, j, k;

    i = j = k = 1;
    i -= j -= k;
    printf("%d\t%d\t%d\n", i, j, k); // 1 0 1
    
    i = j = 1;
    printf("%d\n", i++ - ++j); // -1
    printf("%d\t%d\n", i, j); // 2 2
    
    return 0;
}
