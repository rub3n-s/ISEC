#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SERVER_FIFO "SERVIDOR_N"
#define CLIENT_FIFO "CLIENTE[%d]"

char CLIENT_FIFO_FINAL[50];

void trataSig(int signum) {
    printf("A encerrar via SIGINT\n");
    unlink(CLIENT_FIFO_FINAL);
    exit(1);
}

int main() {
    int fdEnvio;
    char buffer[50];

    if (signal(SIGINT,trataSig)==SIG_ERR) {
        perror("Erro SIGINT");
        return -1;
    }

    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,getpid());
    if (mkfifo(CLIENT_FIFO,0666)==-1) {
        perror("FIFO Cliente");
        return -1;
    }

    do {
        printf("Enviar -> ");
        scanf("%s",buffer);

        fdEnvio = open(SERVER_FIFO,O_WRONLY);
        if (fdEnvio == -1) {
            perror("Erro a abrir cliente para escrita");
        }
        int size = write(fdEnvio,&buffer,sizeof(buffer));
        if (size < 0) {
            perror("Erro a enviar dados -> dados incompletos");
        }
    } while(strcmp(buffer,"sair")!=0);

    unlink(CLIENT_FIFO_FINAL);

    return 0;
}