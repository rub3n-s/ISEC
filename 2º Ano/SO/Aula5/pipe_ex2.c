#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pf[2], fp[2];
	char buffer[50];
	int pid;
	pipe(pf);	pipe(fp);
	pid = fork();
	switch(pid) {	
		case -1:
			perror("erro");
			return -1;
		case 0:
			close(STDIN_FILENO);
			dup(pf[0]);
			close(pf[1]);			

			close(STDOUT_FILENO);
			dup(fp[1]);
			close(fp[0]);

			close(pf[0]); close(fp[1]);
			execl("./ola",NULL);

		default:
			close(pf[0]);
			write(pf[1],"hello world!",13);

			close(fp[1]);
			read(fp[0],buffer, 49);
			printf("%s\n",buffer);
	}
}
