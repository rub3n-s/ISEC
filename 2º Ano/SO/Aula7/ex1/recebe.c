#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define SERVER_FIFO "teste"

typedef struct {
    pid_t pid_cliente;
    char texto[100];
} mensagem;

int main() {
    //char msg[50];
    mensagem msg;

    /* 1) criar o fifo e fazer as verificações */
    if (mkfifo(SERVER_FIFO, 0666) == -1) {
        if (errno == EEXIST) {
            printf("erro ja existe ou o programa ja esta a correr\n");
        }
        printf("Erro a abrir fifo");
        return 1;
    }

    /* 2) abrir para leitura e fazer as verificações */
    int fd_leitura = open(SERVER_FIFO, O_RDONLY);
    if (fd_leitura == -1) {
        printf("erro\n");
        return 1;
    }

    /* 3) ler e verificar se o numero de bytes lidos é > 0 */
    int size = read(fd_leitura,&msg,sizeof(msg));
    if (size > 0) {
        printf("Recebi a mensagem [%s], com o tamanho [%d bytes]", msg.texto, size);
    }

    close(fd_leitura);  // fecha
    unlink(SERVER_FIFO);    // apaga

    return 0;
}