#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int p2f[2], f2p[2];
    char buffer[50];

    pipe(p2f); pipe(f2p);

    int id = fork();
    switch(id) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            close(STDIN_FILENO);
            dup(p2f[0]);
            close(p2f[1]);

            close(STDOUT_FILENO);
            dup(f2p[1]);
            close(f2p[0]);

            close(p2f[0]); close(f2p[1]);

            execl("./teste",NULL);

        default:
            close(p2f[0]);
            write(p2f[1],"sim ",4);

            close(f2p[1]);
            read(f2p[0],buffer,sizeof(buffer));

            printf("Teste [%s]\n",buffer);
    }
}