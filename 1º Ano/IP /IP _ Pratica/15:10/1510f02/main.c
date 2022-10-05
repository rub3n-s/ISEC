//
//  main.c
//  1510f02
//
//  Created by Rúben Mendes Santos on 15/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i = 10;
    float f = 4.354;
    
    printf("%f\n", f);
    printf("%4.2f\n", f);
    printf("%0.4f\n", f);
    printf("%0.0f\n", f);

    printf("%4.2e\n", f);
    printf("%d\n", i);
    printf("%4d\n", i);
    printf("%-4d\n", i);
    printf("%4.2d\n", i);
    printf("%.4d\n", i);
    
    return 0;
}
