#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv) {
    char original[5][20] = {"ola","mundo","bem","obrigado","adeus"};
    char traducao[5][20] = {"bonjour","monde","bien","merci","au revoir"};
    int existe = 0, fd[2];
    pipe(fd);
    for (int i = 0; i < 5; i++) {
        if (strcmp(argv[1],original[i])==0) {
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
            int size = write(fd[1],traducao[i],sizeof(traducao[i]));
            if (size == -1)
                perror("write - dfran");
            existe = 1;
            break;
        }
    }
    if (existe==0)
        printf("unkown\n");
    return 0;
}