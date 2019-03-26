#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

/* Limpa buffer do teclado para Windows e Linux */
void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

int main () {

	int anterior = 0, aux = 0;
	int atual = 1;
	printf("%u, ", anterior);
	printf("%u, ", atual);
	for(int i=0; i<10; i++) {
		aux = atual;
		atual = anterior + atual;
		anterior = aux;

		printf("%u, ", atual);
	}
	printf("\n");

	return 0;
}