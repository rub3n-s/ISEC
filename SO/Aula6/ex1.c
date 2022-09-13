#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int contador = 0;

void handler_funcSinal(int signum) {
    printf("\n Ai \n");
    if (++contador == 5) {
        printf("\nok, pronto\n");
        exit(1);
    }
}

int main() {
    char nome[50];
    printf("PID[%d]\n", getpid());
    struct sigaction sa;
    sa.sa_handler = handler_funcSinal;
    //sa.sa_flags = SA_RESTART|SA_SIGINFO;
    if (sigaction(SIGINT,&sa,NULL)==-1) //sigaction tem retorno, entao deve ser validado
        perror("erro");
    do {
        printf("nome: ");
        scanf("%s", nome);

        if(strcmp(nome,"sair") != 0)
            printf("\nOlá [%s]\n", nome);
    } while(strcmp(nome,"sair")!=0);
    return 0;
}