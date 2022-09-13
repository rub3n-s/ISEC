#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	printf("Ola\n");
	printf("%d", getpid());
	execv("./b", argv);
	printf("\nainda estou aqui\n");	// esta linha só é executada no final de executar o ficheiro b
	return 0;
}
