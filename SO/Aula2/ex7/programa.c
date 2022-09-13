#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
for (int i = 1; i < argc; i++)
	printf("%s\n", argv[i]);

// while
printf("opção sem ponteiros e sem argc\n");
i = 1;
while (argv[i] != NULL) {
	printf("Argumento [%d]: %s\n", i, argv[i]);
	i++;
}

// com ponteiros
printf("opcao com ponteiros e sem argc\n");
i = 1;
char *ponteiro = argv[1];
while (ponteiro != NULL) {
	printf("Argumento [%d]: %s\n", i, argv[i]);
	ponteiro = argv[++i];
}
return 0;
}
