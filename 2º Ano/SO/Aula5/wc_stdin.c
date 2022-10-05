#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main {
	int i;
	close(STDIN_FILENO);
	open("output_ls.txt", O_RDONLY);
	execlp("wc","wc",NULL);
}
