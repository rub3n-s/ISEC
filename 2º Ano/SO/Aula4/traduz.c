#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	char traducao;
	char palavra[50];
	int id;

	id = fork();

	do {
		printf("palavra: ");
		scanf("%s", palavra);
		printf("x (ingles) / f (frances): ");
		scanf("%c", &traducao);
		if (id < 0)
			printf("Erro\n");
		else if (id == 0) {
			switch(traducao) {
				case 'x':
					execlp("./ding", "ding", palavra, NULL);
					break;
				case 'f':
					execlp("./dfran", "dfran", palavra, NULL);
					break;
					
			}
		} else if (id > 0) 
			wait(NULL);
	}
	return 0;
}
