#include <stdio.h>

int valor[1] = {10};

int funcao (int parametro[]) {
	printf("Valor passado no parametro: %i\n", parametro[0]);
	parametro[0] = 20;
	printf("Parametro modificado na funcao: %i\n", parametro[0]);
}

int main() {
	printf("Valor antes da funcao: %i\n", valor[0]);
	funcao(valor);
	printf("Valor depois da funcao: %i\n", valor[0]);
	return 0;
}