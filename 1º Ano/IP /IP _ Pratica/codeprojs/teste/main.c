#include <stdio.h>
#include <stdlib.h>

int main()
{
    float TX_A, TX_B;
    int pop_a, pop_b, num_anos;

    TX_A = 0.052;
    TX_B = 0.018;
    pop_a = 500;
    pop_b = 1500;
    num_anos = 0;

    while (pop_a <= pop_b) {
        pop_a = pop_b + ( 0.052 * pop_a );
        pop_b = pop_b + ( 0.018 * pop_b );

        printf("pop_a = (ano %d): %d \n", num_anos, pop_a);
        printf("pop_b = (ano %d): %d \n", num_anos, pop_b);
    }

    printf("num anos: %d", num_anos);

    return 0;
}
