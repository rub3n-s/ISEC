#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#define SERVER_FIFO "teste"

typedef struct {
    pid_t pid_cliente;
    char texto[100];
} mensagem;

int main() {
    //char msg[100];
    mensagem msg;
    
    strcpy(msg.texto,"Ola mundo!");

    msg.pid_cliente = getpid();

    /* 1) abrir para escrita e fazer as verificações */
    int fd_escrita = open(SERVER_FIFO, O_WRONLY);
    if (fd_escrita == -1) {
        printf("Erro a abrir o fifo\n");
        return 1;
    }

    /* 2) escreve e faz verificação de bytes */
    int size  = write(fd_escrita, &msg, sizeof(msg));
    if (size == 0)
        printf("erro no envia\n");

    close(fd_escrita);

    return 0;
}