#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   
#include <signal.h>
#include <sys/types.h>

int main() {
    int pid;
    printf("\nqual o pid\n");
    scanf("%d",&pid);
    union sigval val;
    val.sival_int = 123;
    //sigqueue(pid,SIGUSR1,val); /*nao tem em mac os*/
    kill(pid,SIGUSR1);
    return 0;
}


/* nao e preciso criar porque esta definida dentro do signal
union sigval {
    int sival_int;
    int *sival_ptr;
}
*/