#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char palavra[20], resposta[20];
    char op;
    int pf[2], fp[2];

    pipe(pf); pipe(fp);
    
    int id = fork();
    
    switch(id) {
        case -1:
            perror("fork");
            return -1;
        case 0:
			close(STDIN_FILENO);
			dup(pf[0]);
			close(pf[1]);			

			close(STDOUT_FILENO);
			dup(fp[1]);
			close(fp[0]);

			close(pf[0]); close(fp[1]);

            execl("./rding",NULL);

        default:
            printf("Palavra: ");
            gets(palavra);

			close(pf[0]);
			write(pf[1],palavra,sizeof(palavra));

			close(fp[1]);
			read(fp[0],resposta, sizeof(resposta));
            
            printf("traducao [%s]\n",resposta);
    }
    
    return 0;
}