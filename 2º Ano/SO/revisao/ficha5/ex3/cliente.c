#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SERVIDOR "server"

int main() {
    char buffer[50];
    
    int fd_escrita = open(SERVIDOR,O_WRONLY);
    if (fd_escrita == -1) {
        unlink(SERVIDOR);
        exit(-1);
    }

    do {
        printf("enviar para servidor: ");
        scanf("%s",buffer);

        int size = write(fd_escrita,&buffer,sizeof(buffer));
        if (size < 0) {
            perror("write - dados incompletos");
        }
    } while(strcmp(buffer,"sair")!=0);

    unlink(SERVIDOR);
    close(fd_escrita);
    return 0;
}