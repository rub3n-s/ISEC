#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int ID;
	
	printf("%d\n", getpid());

	ID = fork();
	
	if(ID < 0)
		printf("Erro\n");
	else if(ID == 0) {
		printf("Sou o filho, com o PID %d\n", getpid());
		printf("O PID do meu pai é %d\n", getppid());
	}
	else if (ID > 0) {
		printf("Sou o pai, com o PID %d\n", getpid());
		printf("%d\n", ID);
		wait(NULL);
	}
	return 0;
}
