#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char opcao[4];
    printf("'port' ou 'ing'?\nOpção: ");
    scanf("%s", opcao);

    if (strcmp(opcao,"port")==0)
        //execl("./port","./port",NULL);
        execlp("./port","port",NULL);
    else if (strcmp(opcao,"ing")==0)
        execl("./ing","./ing",NULL);
    else 
        printf("Opção inválida\n");

    
    return 0;
}