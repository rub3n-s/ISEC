#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void funcSinal(int signum, siginfo_t *info, void *secret) {
    printf("\nRecebi o SINAL - [%d]\n", signum);
    printf("Do PID[%d]\n", info->si_pid);
    printf("Com o valor [%d]\n", info->si_value);
}
int main() {
    int i;
    printf("PID[%d]",getpid());
    struct sigaction sa;
    sa.sa_sigaction = funcSinal;    // 3 parametros
    sa.sa_flags = SA_SIGINFO; // para enviar info
    sigaction(SIGUSR1,&sa,NULL);
    scanf("%d", &i);
    return 0;
}