#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int numero = atoi(getenv("abcd"));
    //int numero = atoi(environ("abcd"));
    printf("[%d]\n", numero);
    return 0;
}