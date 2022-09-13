#include <signal.h>
#include <stdio.h>
#include <unistd.h>
//void handler_funcSinal(int signum) {
void handler_funcSinal(int signum, siginfo_t *info, void *secret) {
    printf("\n[SINAL - %d]\n", signum);
}
int main() {
    int i;
    printf("PID[%d]", getpid());
    struct sigaction sa;
    //sa.sa_handler= handler_funcSinal; // só tem parametro do 
    sa.sa_sigaction = handler_funcSinal;    // 3 parametros
    sigaction(SIGINT,&sa,NULL);
    while(1) {

    }
    return 0;
}