#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso_max, peso_somado, peso_inserido, peso_medio;
    int contador = 0;

    peso_max = peso_inserido = 0.0;

    do {
        printf("Insira peso: ");
        scanf("%f", &peso_inserido);

        if (peso_inserido >= 60.0) {
            peso_somado += peso_inserido;
            contador++;
        } else if (peso_inserido > peso_max){
            peso_max = peso_inserido;
        }
    } while (peso_inserido >= 0.0);

    peso_somado = peso_somado / contador;

    printf("Peso Max: %.2f \n", peso_max);
    printf("Media: %.2f", peso_somado);

    return 0;
}
