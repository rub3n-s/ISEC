#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
	char palavra[50];
	int id;

	do {
		printf("palavra: ");
		scanf("%s", palavra);
		
		id = fork();		
			
		if (id < 0) {
			printf("Erro\n");
		}
		else if (id == 0) {
			execlp("./ding", "ding", palavra, NULL);
		}
		else if (id > 0)
			wait(NULL);
		
	} while(strcmp(palavra,"fim"));

	return 0;
}
