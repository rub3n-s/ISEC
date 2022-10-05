#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char original[5][20] = {"ola","mundo","bem","obrigado","adeus"};
    char traducao[5][20] = {"hello","world","fine","thank you","bye"};
    int existe = 0;
    char buffer[20];

    scanf("%s",buffer);
    for (int i = 0; i < 5; i++) {
        if (strcmp(buffer,original[i])==0) {
            existe = 1;
            printf("%s",traducao[i]);
            break;
        }
    }
    if (existe==0)
        printf("unkown\n");
    return 0;
}