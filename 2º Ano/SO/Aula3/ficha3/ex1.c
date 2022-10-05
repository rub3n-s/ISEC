#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char frase[150];

	fflush(stdout);
	setbuf(stdout,NULL);

	printf("Introduza uma cadeira de caracteres: ");
	scanf("%s", frase);
	printf("%s", frase);

	return 0;
}
