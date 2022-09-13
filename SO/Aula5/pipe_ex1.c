#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int PF[2];
	int FP[2];
	char buffer[13], buffer2[8];
	pipe(PF);
	pipe(FP);
	int pid = fork();
	switch(pid) {
		case -1:
			perror("erro");
		case 0:
			close(PF[1]);
			read(PF[0], buffer, sizeof(buffer));
			close(PF[0]);
			printf("%s\n",buffer);

			close(FP[0]);
			write(FP[1],"resposta",8);
			close(FP[1]);
		default:
			close(PF[0]);
			write(PF[1],"hello world!",11);
			close(PF[1]);

			close(FP[1]);
			read(FP[0], buffer2, sizeof(buffer2));
			close(FP[0]);
			printf("%s\n", buffer2);
	}
}

