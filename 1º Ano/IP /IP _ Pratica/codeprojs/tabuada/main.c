#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i;

    printf("tabuada: \n");
    //scanf("%d", &t);

    for (t=1; t<=9; t++) {
        for (i = 1; i <= 10; i++) {
            printf("%d x %d = %d \n", t, i, t * i);
        }
        printf("\n");
    }

    return 0;
}
