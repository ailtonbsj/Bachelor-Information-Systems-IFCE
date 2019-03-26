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

unsigned fatorial (unsigned val) {
	if(val == 0) return 1;
	else return val * fatorial(val-1);
}

int main () {
	unsigned num, res;
	printf("Digite um numero: ");
	scanf("%u", &num);
	clearBufferKey();

	res = fatorial(num);
	printf("O fatorial eh %u\n", res);
	return 0;
}