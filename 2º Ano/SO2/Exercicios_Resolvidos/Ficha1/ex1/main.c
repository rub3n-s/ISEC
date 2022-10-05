#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX 256

int main(int argc, char * argv[]) {
	char frase[MAX] = "Olá mundo!";
	printf("Frase: %s. Tamanho: %d \n",frase,strlen(frase));
	getchar();
	return 0;
}