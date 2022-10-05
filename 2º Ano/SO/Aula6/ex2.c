#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int n = 20; int pontuacao = 0; int perdeu = 0;
void jogo () {
    srand(time(NULL));
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int soma = num1 + num2, somaUser;
    printf("\nIntroduza o valor da conta: [%d] [%d]\n", num1, num2);
    if (scanf("%d", &somaUser) != 1) {
        perror("Não introduziu nada - Perdeu\n");
    }
    if (soma == somaUser) {
        pontuacao++;
        printf("Acertou e tem [%d] pontos\n", pontuacao);
        n--;
    } else {
        n--;
        printf("Perdeu\n");
        if (++perdeu == 2)
            exit(1);
        else
            printf("\nTem mais uma tentativa\n");
    }
}

void handler_sigalarm(int signum, siginfo_t *info, void *v) {
    printf("Acabou o tempo - Perdeu\n");
    exit(1);
}

int main() {
    int i = 0, n = 0;
    struct sigaction sa;
    sa.sa_sigaction = handler_sigalarm;
    sa.sa_flags = SA_RESTART|SA_SIGINFO;
    sigaction(SIGALRM,&sa,NULL);
    while(1) {
        if (i==5){
            exit(1);   
        }
        else {
            alarm(n);
            jogo();
            i++;
        }
    }
    return 0;
}

