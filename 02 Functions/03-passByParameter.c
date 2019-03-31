#include <stdio.h>

int valor = 10;

int funcao (int parametro) {
	printf("Valor passado no parametro: %i\n", parametro);
	parametro = 20;
	printf("Parametro modificado na funcao: %i\n", parametro);
}

int main() {
	printf("Valor antes da funcao: %i\n", valor);
	funcao(valor);
	printf("Valor depois da funcao: %i\n", valor);
	return 0;
}