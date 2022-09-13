#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SERVER_FIFO "Servidor_N"
#define CLIENT_FIFO "Cliente[%d]"

char CLIENT_FIFO_FINAL[100];

typedef struct { 
    char resposta[200];
} Servidor;

typedef struct {
    int pid;
    char resposta[200];
} Cliente;

void trataSig(int signum) {
    printf("A sair via SIGINT\n");
    unlink(SERVER_FIFO);
    unlink(CLIENT_FIFO_FINAL);
    exit(1);
}

int main() {
    Servidor servidor;
    Cliente cliente;

    struct timeval tv;
    fd_set read_fds;

    if (signal(SIGINT,trataSig)==SIG_ERR) {
        perror("SIGINT");
        exit(-1);
    }

    if (mkfifo(SERVER_FIFO,0666)==-1) {
        perror("Fifo SERVER");
        exit(-1);
    }

    int fdRecebeCliente = open(SERVER_FIFO, O_RDWR);
    if (fdRecebeCliente == -1) {
        perror("Erro a abrir pipe SERVER para leitura/escrita");
        exit(-1);
    }

    printf("A iniciar servidor...\n\n");
    
    do {
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fdRecebeCliente,&read_fds);

        int nfd = select(fdRecebeCliente+1,&read_fds,NULL,NULL,&tv);

        if (FD_ISSET(0,&read_fds)) {
            fflush(stdin);
            gets(servidor.resposta);

            int fdEnvio = open(CLIENT_FIFO,O_WRONLY);
            if (fdEnvio == -1) {
                perror("Erro a abrir pipe CLIENTE para escrita");
                close(fdEnvio);
            }
            write(fdEnvio,&servidor,sizeof(servidor));
            close(fdEnvio);
        }

        if (FD_ISSET(fdRecebeCliente,&read_fds)) {
            fflush(stdout);
            int size = read(fdRecebeCliente,&cliente,sizeof(cliente));
            if (size < 0) {
                perror("Dados recebidos incompletos");
                exit(-1);
            }
            printf("Recebido do Cliente[%d] -> [%s]\n",cliente.pid,cliente.resposta);
        }
    } while(strcmp(servidor.resposta,"sair")!=0);

    unlink(SERVER_FIFO);
    close(fdRecebeCliente);

    return 0;
}