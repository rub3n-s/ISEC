#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
	int i;
	//scanf("%d", &i;
	close(STDOUT_FILENO);
	open("output_ls.txt", OWRONLY);
	//scanf("%d", &i);
	execlp("ls","ls",NULL);
}
