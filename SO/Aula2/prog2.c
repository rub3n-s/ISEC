#include <stdio.h>
#include <string.h>

int main() {
	int numero = 0;
	char c[50];	
	do {
		printf("Introduza um numero : ");
		scanf("%d",&numero);
		printf("Quadrado: %d\n", numero * numero);
	
		printf("'fim' para terminar!\n");
		scanf("%s", c);
	} while (strcmp(c,"fim") != 0);
	
	return 0;
}
