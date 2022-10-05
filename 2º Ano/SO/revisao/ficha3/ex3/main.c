#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while(1) {
        fflush(stdout);
        for (int i = 0; i < 5; i++)
            printf("*");
        setbuf(stdout,NULL);
        sleep(1);
        printf("\n");
    }
    return 0;
}