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
	unsigned num;

	printf("Digite um numero: ");
	scanf("%u",&num);
	clearBufferKey();

	if(num % 2 == 0) printf("Numero eh par.\n");
	else printf("Numero eh impar.\n");

	return 0;
}