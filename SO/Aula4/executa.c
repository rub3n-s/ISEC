#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	char buffer[50];
	printf("port/ingl: "); 
	scanf("%s", buffer);

	if (strcmp(buffer,"port") == 0)
		execl("./port", buffer, NULL); // execl
	else if (strcmp(buffer,"ingl") == 0)
		execlp("./ing", "ing", NULL); // execlp
	else
		printf("opcoes: port ou ingl\n");

	printf("fim\n");
	return 0;
}
