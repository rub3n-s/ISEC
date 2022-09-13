#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
	char *ing2[] = {"aas", "asfdas", "..."};
	char ing[3][50] = {"hello", "world", "example"};
	char port[3][50] = {"ola", "mundo", "exemplo"};
	for (int i = 0; i <= argc; i++)
		if (strcmp(argv[1], port[i]) == 0)
			printf("%s\n", ing[i]);
	return 0;
}
