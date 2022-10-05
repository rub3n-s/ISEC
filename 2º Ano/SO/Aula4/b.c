#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	printf("%d", getpid());
	printf("%s", argv[0]);
	printf("%s", argv[1]);
	printf("%s", argv[2]);	
	return 0;
}
