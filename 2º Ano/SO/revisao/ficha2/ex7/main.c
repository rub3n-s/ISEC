#include <stdio.h>
#include <stdlib.h>

int main(int argc,char ** argv) {
    int numero = 0;
    if (argc > 0)
        numero = atoi(argv[1]);

    if (numero > 0) {
        printf("Tabuada do [%d]\n", numero);
        for (int i = 0; i <= 10; i++)
            printf("[%d] x [%d] = [%d]\n", numero, i, numero * i);
    } else {
        printf("Tem de ser maior que zero!\n");
    }
    
    return 0;
}