
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int contador = 0;

void sig_handler(int signum) {
    printf("\nai\n");
    if (++contador == 5) {
        printf("\nok, pronto\n");
        exit(1);
    }
}

int main() {
    char nome[50];
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    if (sigaction(SIGINT,&sa,NULL) == -1)
        perror("signal");
    do {
        printf("Nome: "); gets(nome);
        printf("Olá [%s]\n",nome);
    } while(strcmp(nome,"sair")!=0);    
    return 0;
}