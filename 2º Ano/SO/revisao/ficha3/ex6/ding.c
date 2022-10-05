#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv) {
    char original[5][20] = {"ola","mundo","bem","obrigado","adeus"};
    char traducao[5][20] = {"hello","world","fine","thank you","bye"};
    int existe = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(argv[1],original[i])==0) {
            printf("\ntraducao(ingles): [%s] -> [%s]\n\n",argv[1],traducao[i]);
            existe = 1;
            break;
        }
    }
    if (existe==0)
        printf("unkown\n");
    return 0;
}