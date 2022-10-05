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
    unlink(SERVER_FIFO);
    unlink(CLIENT_FIFO_FINAL);
    exit(1);
}

int main() {
    char buffer[20];
    int fdRecebe;

    if (signal(SIGINT,trataSig)==SIG_ERR) {
        perror("Erro SIGINT");
        return -1;
    }

    if (mkfifo(SERVER_FIFO,0666)==-1) {
        perror("FIFO Servidor");
        return -1;
    }

    printf("Servidor aberto...\n");

    fdRecebe = open(SERVER_FIFO, O_RDONLY);
    if (fdRecebe == -1) {
        perror("Erro a abrir servidor para leitura");
    }

    do {
        fflush(stdout);
        int size = read(fdRecebe,&buffer,sizeof(buffer));
        if (size < 0)
            perror("Erro a receber dados -> dados incompletos");
        buffer[sizeof(buffer)-1] = '\0';
        printf("Recebido [%s]\n",buffer);
    } while(strcmp(buffer,"sair") != 0);

    unlink(SERVER_FIFO);

    return 0;
}