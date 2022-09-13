#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    float x,y;

    scanf("%f%d%f%d", &x, &i, &y, &j);// 12    12.4    35.2    3

    printf("x=%f \t i=%d \t y=%f \t j=%d", x, i, y, j); //12.000000     12     0.4     35
    return 0;
}
