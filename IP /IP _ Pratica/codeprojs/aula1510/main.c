#include <stdio.h>
#include <stdlib.h>

int main()
{
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
}
